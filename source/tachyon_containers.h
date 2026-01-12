
#pragma once

namespace tyon
{

template <typename T>
struct node_link
{
    i64 index = -1;
    i64 prev = -1;
    i64 next = -1;
    T value {};
};

template <typename T>
struct linked_list
{
    using t_self = linked_list<T>;
    using t_node = node_link<T>;
    array< t_node > nodes;
    // The index of the first node in the list
    i64 head_ = -1;
    // The index of the last node in the list
    i64 tail_ = -1;
    // The length of the list from head to tail
    isize list_size = 0;

    PROC resize( isize count )
    {   nodes.resize( count ); }

    PROC size_grow( isize count )
    {
        nodes.resize( nodes.size() + count );
    }

    PROC push_tail( T arg ) -> t_node*
    {
        t_node* new_node = &nodes.push_tail( {} );
        new_node->index = list_size;
        new_node->value = arg;

        bool no_tail = (this->tail_ < 0);
        bool no_head = (this->head_ < 0);
        if (no_tail)
        {   head_ = new_node->index;
            tail_ = head_;
        }
        new_node->prev = tail_;
        tail_ = new_node->index;

        // Make sure 'prev' of first node doesn't point to anything
        if (no_head)
        {   new_node->prev = -1;
        }
        bool prev_exists = (new_node->prev >= 0);
        if (prev_exists)
        {   nodes[ new_node->prev ].next = new_node->index;
        }

        ++list_size;
        return new_node;
    }

    PROC pop_tail( T arg )
    {
        monad<t_node> result;
        // return error on bad invalid tail but let the last value pop off
        if (tail_ < 0)
        { result.error = true; return result; }

        result.index = -1;
        result.value = nodes[ tail_ ];
        // nullify tail so it can be detected as an unused node
        tail() = {};
        nodes.head_size--;

        ERROR_GUARD( (head_ == -1 && tail_ == -1) || (head_ = -1 && tail_ == -1) ||
                     (head_ >= 0 && tail_ >= 0),
                     "Probably a bug if these tests fail" );
        return result;
    }

    PROC
    insert_after( t_node* target_node, T value ) -> t_node*
    {
        ERROR_GUARD( (target_node >= nodes.address(0)) && (target_node <= nodes.address( nodes.size_ )),
                     "A node from outside this container has been used as an argument" );
        t_node* new_node = &nodes.push_tail( {} );
        // Set index before proceeding
        new_node->index = list_size;
        if (target_node->next >= 0)
        {   new_node->next = target_node->next;
        }
        new_node->prev = target_node->index;
        target_node->next = new_node->index;
        new_node->value = value;
        ++list_size;

        ERROR_GUARD( (head_ == -1 && tail_ == -1) || (head_ = -1 && tail_ == -1) ||
                     (head_ >= 0 && tail_ >= 0),
                     "Wut" );
        return new_node;
    }


    PROC remove_node( t_node* arg ) -> void
    {
        ERROR_GUARD( (arg >= nodes.address(0)) && (arg <= nodes.address( nodes.size_ )),
                     "A node from outside this container has been used as an argument" );
        bool prev_valid = (arg->prev >= 0);
        bool next_valid = (arg->next >= 0);
        i32 next_of = arg->next;
        i32 prev_of = arg->prev;
        if (prev_valid && next_valid)
        {   // pass old references to prev and next
            // 1 - 2 - 3
            // 1 next   <-prev 3
            // 1 next->   prev 3
            nodes[ arg->prev ].next = next_of;
            nodes[ arg->next ].prev = prev_of;
        }
        else if (prev_valid)
        {   // Only prev, no next node, nullify that reference and make it the tail
            tail_ = arg->prev;
            nodes[ arg->prev ].next = -1;
        }
        else if (next_valid)
        {   // Only next, no prev node, nullify that reference and make it the head
            head_ = next_of;
            nodes[ next_of ].prev = -1;
        }

        // Clear node to made node detected as empty
        *arg = {};
        arg->prev = -1;
        arg->next = -1;

        nodes.head_size--;
        list_size--;
        ERROR_GUARD( (head_ == -1 && tail_ == -1) || (head_ == -1 && tail_ == -1) ||
                     (head_ >= 0 && tail_ >= 0),
                     "Wut" );
        TYON_LOG( "remove list_size", list_size );
    }

    /** LOOKING links in node order from head to tail */
    PROC operator [] ( isize arg ) -> monad<t_node*>
    {
        monad<t_node*> result;
        t_node* x_node = &nodes[ head_ ];
        if ( head_ < 0 || arg > list_size)
        {   result.error = true;  return result; }

        for (isize i=0; i < arg; ++i)
        {
            ERROR_GUARD( x_node->next >= 0, "Broken link is indicative of a logic issue" );
            x_node = &nodes[ x_node->next ];
        }
        result.value = x_node;
        return result;
    }

    PROC head() -> t_node*
    {   return &nodes[ head_ ]; }

    PROC tail() -> t_node*
    {   return &nodes[ tail_ ]; }

    struct indexer
    {
        isize index = 0;
        t_self* context;
        t_node* value = nullptr;
        isize range_min = 0;
        isize range_max = 0;
        bool do_iteration = false;

        /** Returns true if this iteration should be used */
        PROC forward() -> fresult
        {
            bool next_valid = (value->next < 0);
            do_iteration = (index <= range_max);
            if (do_iteration && next_valid)
            {   TYON_ERROR( "Container must be broken if the next node is negative" );
                TYON_BREAK();
            }
            if (next_valid)
            {   value = &context->nodes[ value->next ];
            }
            index += 1;
            return do_iteration;
        }

        /** Returns true if this iteration should be used */
        PROC backward() -> fresult
        {
            do_iteration = (index - 1 >= range_min);
            if (do_iteration && value->prev < 0)
            {   TYON_ERROR( "Container must be broken if the prev node is negative" );
                TYON_BREAK();
            }
            if (do_iteration)
            {   value = &context->nodes[ value->prev ];
            }
            index -= 1;
            return do_iteration;
        }

        PROC operator == ( indexer& rhs ) -> bool
        {   return this->value->value == rhs.value; }

    };

    /** Uses exact inclusive range

        returns an invalid iterator on invalid range */
    PROC indexer_ranged( isize min = 0, isize max = 0 ) -> indexer
    {
        indexer result;
        // Flag an error is max is outsize of 'list_size' or 'head' is nullptr
        // Uses inclusive max
        if (min < 0 || max < 0 || max > list_size || min > max || head_ < 0) { return result; }

        result = indexer {
            .index = min,
            .context = this,
            .value = head(),
            .range_min = min,
            .range_max = max,
            .do_iteration = true
        };
        return result;
    }

    /** index the full range of the container from head to tail

        returns an invalid iterator on invalid range */
    PROC indexer_full() -> indexer
    {
        return indexer_ranged( 0, list_size -1 );
    }

};

}
