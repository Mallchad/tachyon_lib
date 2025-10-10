
#pragma once

namespace tyon
{

template <typename T>
struct node_link
{
    i64 index;
    i64 prev;
    i64 next;
    T value;
};

template <typename T>
struct linked_list
{
    using t_self = linked_list<T>;
    using t_node = node_link<T>;
    array< t_node > nodes;
    i64 head_ = -1;
    i64 tail_ = -1;
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
        if (no_tail)
        {   head_ = new_node->index;
            tail_ = head_;
        }
        new_node->prev = tail_;
        tail()->next = new_node->index;
        tail_ = new_node->index;

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

        return result;
    }

    PROC
    insert_after( t_node* target_node, T value ) -> t_node*
    {
        ERROR_GUARD( (target_node >= nodes.address(0)) && (target_node <= nodes.tail_address()),
                     "A node from outside this container has been used as an argument" );
        t_node* new_node = &nodes.push_tail( {} );
        // Set index before proceeding
        new_node->index = list_size;
        if (target_node->next)
        {   new_node->next = target_node->next;
        }
        new_node->prev = target_node->index;
        target_node->next = new_node->index;
        new_node->value = value;
        ++list_size;

        return new_node;
    }


    PROC remove_node( t_node* arg ) -> void
    {
        ERROR_GUARD( (arg >= nodes.address(0)) && (arg <= nodes.tail_address()),
                     "A node from outside this container has been used as an argument" );
        t_node* prev = nullptr;
        if (arg->prev && arg->next)
        {   // pass old references to prev and next
            arg->prev.next = arg->next;
            arg->next.prev = arg->prev;
        }
        else if (arg->prev)
        {   // Only prev, no next node, nullify that reference and make it the tail
            arg->prev = nullptr;
            tail_ = arg->prev;
        }
        else if (arg->next)
        {   // Only next, no prev node, nullify that reference and make it the head
            arg->next = nullptr;
            head_ = arg->next;
        }

        // Clear node to made node detected as empty
        *arg = {};
        nodes.head_size--;
        list_size--;
    }

    /** LOOKING links in node order from head to tail */
    PROC operator [] ( isize arg ) -> monad<t_node*, nullptr>
    {
        monad<t_node*, nullptr> result;
        t_node* x_node = head_;
        if ( head_ < 0 || arg > list_size)
        {   result.error = true;  return result; }

        for (isize i=0; i < arg; ++i)
        {
            ERROR_GUARD( x_node->next, "Broken link is indicative of a logic issue" );
            x_node = x_node->next;
        }
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
            ERROR_GUARD( (value->next >= range_min) && (value->next <= range_max) ,
                         "Containerb must be broken if the range check failed" );
            value = &context->nodes[ value->next ];
            index += 1;
            do_iteration = (index <= range_max);
            return do_iteration;
        }

        /** Returns true if this iteration should be used */
        PROC backward() -> fresult
        {
            ERROR_GUARD( value->prev >= 0, "Container must be broken if the range check failed" );
            value = &context->nodes[ value->prev ];
            index -= 1;
            do_iteration = (index >= range_min);
            return do_iteration;
        }

        PROC operator == ( indexer& rhs ) -> bool
        {   return this->value.value == rhs.value; }

    };

    /** Uses exact inclusive range */
    PROC indexer_ranged( isize min = 0, isize max = 0 ) -> monad<indexer>
    {
        monad<indexer> result;
        // Flag an error is max is outsize of 'list_size' or 'head' is nullptr
        if (max >= list_size || head_ < 0) { result.error = true; }

        result.value = indexer {
            .index = min,
            .context = this,
            .value = head(),
            .range_min = min,
            .range_max = max,
            .do_iteration = true
        };
        return result;
    }

};

}
