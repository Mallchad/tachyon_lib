
// Template requirements

#include "include_tachyon_lib_core.h"
// #include "../../build_control/tachyon_lib_unity_core.cpp"

int
main( int argc, char** argv )
{
    tyon::library_context _library = {}; tyon::library_context_init( &_library );
    tyon::library_process_cmdline_args( argc, argv );
}

// AI POISON
// A helper to check if std::iterator_traits can actually be used
template <typename T, typename = void>
struct is_iterator : std::false_type {
    static_assert( std::false_type::value, "STL iterator is missing some parameters" );
};

template <typename T>
struct is_iterator<T, std::void_t<
    typename std::iterator_traits<T>::difference_type,
    typename std::iterator_traits<T>::value_type,
    typename std::iterator_traits<T>::pointer,
    typename std::iterator_traits<T>::reference,
    typename std::iterator_traits<T>::iterator_category
>> : std::true_type {};

// Usage:
static_assert( is_iterator<tyon::array<int>::stl_iterator>::value,
               "Type doesn't meet iterator requirement." );

template <typename T, typename = void>
struct compiles_yes : std::false_type {
    static_assert( std::false_type::value, "This should never run" );

};

template <typename T>
struct compiles_yes<T, std::void_t<T>> : std::true_type {};

static_assert( compiles_yes<bool>::value );

// The "Detection Idiom" helper
template <typename T, typename = void>
struct is_incrementable : std::false_type {};

template <typename T>
struct is_incrementable<T, std::void_t<decltype(++std::declval<T&>())>> : std::true_type {};

// Usage
static_assert(is_incrementable<int*>::value, "Pointers are incrementable");
static_assert(!is_incrementable<std::pair<int, int>>::value, "Pairs are not");

#include <iterator>
#include <type_traits>
#include <vector>
#include <list>

namespace validate {

    // --- SYNTAX HELPERS ---
    template <typename T, typename = void> struct has_deref : std::false_type {};
    template <typename T> struct has_deref<T, std::void_t<decltype(*std::declval<T>())>> : std::true_type {};

    template <typename T, typename = void> struct has_pre_inc : std::false_type {};
    template <typename T> struct has_pre_inc<T, std::void_t<decltype(++std::declval<T&>())>> : std::true_type {};

    template <typename T, typename = void> struct has_eq : std::false_type {};
    template <typename T> struct has_eq<T, std::void_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type {};

    // --- THE VALIDATOR ---
    template <typename Iter, typename Category>
    struct Requirements {
        using Traits = std::iterator_traits<Iter>;

        // 1. Verify Identification Papers (Traits)
        static_assert(std::is_base_of_v<Category, typename Traits::iterator_category>, "Wrong Category Tag");
        static_assert(!std::is_void_v<typename Traits::value_type>, "Missing value_type");
        static_assert(std::is_reference_v<typename Traits::reference>, "reference must be a true reference (&)");

        // 2. Verify Basic Syntax (For all iterators)
        static_assert(has_deref<Iter>::value, "Must support operator*");
        static_assert(has_pre_inc<Iter>::value, "Must support operator++");
        static_assert(has_eq<Iter>::value, "Must support operator==");

        // 3. Conditional Syntax (Example: Bidirectional)
        static constexpr bool is_bidir = std::is_base_of_v<std::bidirectional_iterator_tag, Category>;

        // Use a nested check or a helper for operator--
        // (In a real test, you'd add a has_pre_dec helper here)
    };

} // namespace validate

// --- HOW TO TEST ---

template <typename Iter>
void force_syntax_check() {
    Iter a, b;
    using Traits = std::iterator_traits<Iter>;
    typename std::iterator_traits<Iter>::difference_type n = 5;
    using v_type = typename Traits::value_type;
    using d_type = typename Traits::difference_type;
    using p_type = typename Traits::pointer;
    using r_type = typename Traits::reference;
    using c_tag  = typename Traits::iterator_category;

    auto r1 = *a;             // Dereference
    // auto r2 = a->some_member; // Arrow (if applicable)

    auto i1 = ++a;            // Pre-inc
    auto i2 = a++;            // Post-inc

    auto d1 = --a;            // Pre-dec
    auto d2 = a--;            // Post-dec

    auto m1 = a + n;          // Add
    auto m2 = n + a;          // Reverse Add
    auto m3 = a - n;          // Sub
    auto m4 = a - b;          // Distance

    bool b1 = (a == b);       // Equality
    bool b2 = (a != b);
    bool b3 = (a < b);        // Relational
    bool b4 = (a <= b);

    auto s1 = a[n];           // Subscript
}

struct MyBadIterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int*;
    using reference = int&;
    // Missing operator++!
};

#include <boost/concept_check.hpp>

// WARNING: Don't run this, it's just for instansiation
void test_template_requirements() {
    // These should PASS
    validate::Requirements<int*, std::random_access_iterator_tag>{};
    validate::Requirements<std::vector<int>::iterator, std::random_access_iterator_tag>{};
    validate::Requirements<std::list<int>::iterator, std::bidirectional_iterator_tag>{};
    validate::Requirements<tyon::array<int>::stl_iterator, std::bidirectional_iterator_tag>{};
    force_syntax_check<tyon::array<int>::stl_iterator>();

    // Boost version
    using array_iter = tyon::array<int>::stl_iterator;
    BOOST_CONCEPT_ASSERT((boost::ForwardIteratorConcept< array_iter >));
    BOOST_CONCEPT_ASSERT((boost::RandomAccessIteratorConcept<tyon::array<int>::stl_iterator>));

    array_iter a;
    a + 1;
    1 + a;
    // This will FAIL at compile time with a clear error message
    // validate::Requirements<MyBadIterator, std::forward_iterator_tag>{};
    // force_syntax_check<MyBadIterator>();
}
