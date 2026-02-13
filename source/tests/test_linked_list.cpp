
using namespace tyon;

// extern vector<typed_procedure<void()>> g_tests_list;

void
test_linked_list()
{
    {
        linked_list<i32> push;
        push.push_tail( 1 ); push.push_tail( 2 ); push.push_tail( 3 ); push.push_tail( 4 );
        push.push_tail( 5 ); push.push_tail( 6 ); push.push_tail( 7 ); push.push_tail( 8 );
        push.push_tail( 9 ); push.push_tail( 10 );
        std::vector<int> output;
        bool matches_ref = true;
        bool matches_ref_indexer = true;
        auto reference = std::vector<int>{ 4, 5, 6, 7, 8  };
        auto i_push = push.indexer_ranged( 3, push.nodes.size() - 1 - 2 );
        for (int i=0; i_push.do_iteration; i_push.forward(), ++i)
        {
            // 2 in one test
            auto x_value = i_push.value->value;
            output.push_back( x_value );
            // Collapses on false if any don't match
            // NOTE: The reference is a different container so we use iteration not index.
            matches_ref_indexer &= (x_value == reference.at( i_push.iteration ) );
            TYON_LOG( x_value, reference.at( i_push.iteration ) );
        }
        test( matches_ref, "linked_list push_back matches reference data" );
        test( matches_ref_indexer, "linked_list indexer.index read matches reference data" );
    }

    {
        linked_list<i32> push;
        push.push_tail( 1 ); push.push_tail( 2 ); push.push_tail( 3 ); push.push_tail( 4 );
        push.push_tail( 5 ); push.push_tail( 6 ); push.push_tail( 7 ); push.push_tail( 8 );
        push.push_tail( 9 ); push.push_tail( 10 );
        push.remove_node( push[3].copy_default({}) );
        push.remove_node( push[1].copy_default({}) );
        auto reference = std::vector<int>{ 1,     3,   5, 6, 7, 8, 9, 10 };
        //                                   ^[1]    ^[3]
        auto i_push = push.indexer_full();
        bool matches_ref = true;
        for (; i_push.do_iteration; i_push.forward())
        {
            auto x_value = i_push.value->value;
            // Collapses on false if any don't match
            // NOTE: The reference is a different container so we use iteration not index.
            matches_ref &= (x_value == reference.at( i_push.iteration ));
            TYON_LOG( x_value, reference.at( i_push.iteration ) );
        }
        test( matches_ref, "tyon::linked_list indexer_full() matches reference data" );
    }

}
