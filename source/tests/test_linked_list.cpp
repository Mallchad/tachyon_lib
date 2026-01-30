
using namespace tyon;

// extern vector<typed_procedure<void()>> g_tests_list;

void
test_linked_list()
{
    linked_list<i32> push;
    push.push_tail( 1 );
    push.push_tail( 2 );
    push.push_tail( 3 );
    push.push_tail( 4 );
    push.push_tail( 5 );
    push.push_tail( 6 );
    push.push_tail( 7 );
    push.push_tail( 8 );
    push.push_tail( 9 );
    push.push_tail( 10 );

    TYON_LOG( "Testing push to linked-list" );
    fstring line_1;
    fstring line_2;
    std::vector<int> output;
    auto i_push = push.indexer_ranged( 0, push.nodes.size() - 1 );
    for (; i_push.do_iteration; i_push.forward())
    {
        line_2 += fmt::format( "{}", i_push.index );
        line_1 += fmt::format( "{}", i_push.value->value );
        output.push_back( i_push.value->value );
    }
    TYON_LOG( line_2 );
    TYON_LOG( line_2 );
    auto compare = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    TYON_LOGF( "matchin_output: {}", memcmp( output.data(), compare.data(), compare.size())  );

    push.remove_node( push[3] );
    push.remove_node( push[1] );
    TYON_LOG( push[0].value[0].value, push[1].value[0].value, push[2].value[0].value );
    i_push = push.indexer_full();
    for (; i_push.do_iteration; i_push.forward())
    {
        TYON_LOG( i_push.value->value );
    }

}
