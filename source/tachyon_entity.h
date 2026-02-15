
#pragma once

namespace tyon
{

    /* Meta-Programming type that delays static_assert evaluation until a template is instansiated */
    template <typename T>
    struct meta_type_present_fulfilled : std::false_type {};

    template <typename T>
    struct entity_type_definition
    {
        static_assert( meta_type_present_fulfilled<T>::value,
                       "\nYou must provide your own template specialization \n"
                       "https://en.cppreference.com/w/cpp/language/template_specialization.html\n\n"
                       "Sorry if this looks strange or is unfamiliar to you, but essentially it \n"
                       "just means we have created a template class and we want you to create a \n"
                       "version with your type filled in- with all data and functions defined.\n"
                       "some examples will be provided in this file" );
    };

    /* Non-templated copy of type info and functions, useful for runtime invarience */
    struct entity_type
    {
        cstring name;
        u128 id;

        /* TODO: May need to add per-entity type erased callbacks later. We'll
         * see how this works in practice since usage might change the design.
         */
        generic_procedure<void(void*)> context_tick;
        generic_procedure<void(void*)> destroy_all;
    };

    /** Typed subcontext with holds all the entities for 1 type */
    template <typename t_entity>
    struct entity_type_context
    {
        array< t_entity > list;
    };

    /** Global manager of all entities.

        It's worth remembering that you can have more than one entity context per program but the
        active one is determined by entity_context.  */
    struct entity_context
    {
        using typed_context = void*;
        array< entity_type > types;
        array< typed_context > type_contexts;
    };

    template<>
    struct entity_type_definition<file>
    {
        using t_entity = file;
        using t_context = entity_type_context<t_entity>;
        static constexpr cstring name = "tyon::file";
        static constexpr u128 id = uuid("980ad1e7-ea61-49de-8131-bb1b4060dc73");

        PROC allocate() -> void
        {}
        PROC init( t_entity* arg ) -> fresult
        {
            arg->id = uuid_generate();
            return false;
        }
        PROC destroy( t_entity* arg ) -> void
        {}

        PROC tick( t_entity* arg ) -> void
        {}

        static PROC context_tick( void* context ) -> void
        {}

        static PROC destroy_all( void* context ) -> void
        {}

    };

    /** Static instance of type definition data. */

    template <typename t_entity>
    static entity_type_definition<t_entity> entity;

    /** Static context instance of entities for a single entity type */
    template <typename t_entity>
    extern entity_type_context<t_entity>* g_entity_type = nullptr;

    extern entity_context* g_entity;

    // SECTION: User Overriden Entity Functions

    template <typename t_entity>
    PROC entity_allocate() -> t_entity*
    {
        // TODO: We need to give the context to the allocate hook.
        entity<t_entity>.allocate();
        auto& entity_list = g_entity_type<t_entity>->list;
        return &entity_list.push_tail({});
    }

    template <typename t_entity>
    PROC entity_init( t_entity* arg ) -> fresult
    {
        entity<t_entity>.init( arg );
        return false;
    }

    template <typename t_entity>
    PROC entity_destroy( t_entity* arg ) -> void
    {
    }

    template <typename t_entity>
    PROC entity_tick( t_entity* arg ) -> void
    {
        entity<t_entity>.tick( arg );
    }

    template <typename t_entity>
    PROC entity_tick_all() -> void
    {
        auto& entity_list = g_entity_type<t_entity>->list;
        for (i32 i=0; i < entity_list.size(); ++i)
        {
            entity<t_entity>.tick( &entity_list[i] );
        }
    }

    // Shared Entity Functions

    /** Convenience function to get a type-dependent context because tempalted
     * variables are nor a familar concept to most developers */
    template <typename t_entity>
    PROC entity_get_context() -> entity_type_context<t_entity>*
    {   return g_entity_type<t_entity>;
    }

    template <typename t_entity>
    PROC entity_search( uid arg ) -> monad<t_entity*>
    {
        monad<t_entity*> result;
        result.error = true;

        auto& entity_list = g_entity_type<t_entity>->list;
        t_entity* x_entity;
        for (i64 i=0; i < entity_list.size(); ++i)
        {
            x_entity = entity_list.data + i;
            if (x_entity->id == arg)
            {   result.value = x_entity;
                result.error = false;
                break;
            }
        }
        return result;
    }

    template <typename t_entity>
    PROC entity_search_name( fstring name ) -> monad<t_entity*>
    {
        monad<t_entity*> result;
        result.error = true;

        auto& entity_list = g_entity_type<t_entity>->list;
        t_entity* x_entity;
        for (i64 i=0; i < entity_list.size(); ++i)
        {
            x_entity = entity_list.data + i;
            if (x_entity->name == name)
            {   result.value = x_entity;
                result.error = false;
                break;
            }
        }
        return result;
    }

    template <typename t_entity>
    PROC entity_type_validator() -> void
    {
        using T = t_entity;
        T _a;                                     // ERROR: User defined entity implimented incorrectly
        entity_init( &_a );                       // ERROR: User defined entity implimented incorrectly
        entity_destroy( &_a );                    // ERROR: User defined entity implimented incorrectly
        entity_tick<T>( &_a );                    // ERROR: User defined entity implimented incorrectly

        entity_search<T>( uid() );                // ERROR: User defined entity implimented incorrectly
        entity_search_name<T>( "" );              // ERROR: User defined entity implimented incorrectly
        entity_context entity_;                   // ERROR: User defined entity implimented incorrectly
        T*             _b = entity_allocate<T>(); // ERROR: User defined entity implimented incorrectly
        entity_init( _b );                        // ERROR: User defined entity implimented incorrectly

        entity_type type;                         // ERROR: User defined entity implimented incorrectly
        t_entity*   context;                      // ERROR: User defined entity implimented incorrectly
    };

    template <typename t_entity>
    PROC entity_type_register() -> void
    {
        if (g_entity_type<t_entity> != nullptr)
        {   TYON_ERRORF( "Tried to register a type that has already been registered \n"
            "Type Name: {}    "
            "Type UUID: {}", entity<t_entity>.name, uid(entity<t_entity>.id) );
            return;
        }

        /* Instansiate function to validate type, DON'T ACTUALLY call it, it's
           not defined what shuld happen */
        if (false) { entity_type_validator<t_entity>(); }
        // Instansiate type data
        (void)entity<t_entity>;

        entity_type new_type;
        new_type.name = entity<t_entity>.name;
        new_type.id = entity<t_entity>.id;
        new_type.context_tick = entity<t_entity>.context_tick;
        new_type.destroy_all = entity<t_entity>.destroy_all;

        // Add typed subcontext to global list on contexts
        auto new_context = memory_allocate< entity_type_context<t_entity> >(1);
        g_entity->types.push_back( new_type );
        g_entity->type_contexts.push_back( new_context );

        // Add context to easily accessible global handle too
        g_entity_type<t_entity> = new_context;
    }

    template <typename t_entity>
    struct entity_uid
    {
        using t_self = entity_uid<t_entity>;
        i64 id;
        u128 uuid;

        CONSTRUCTOR entity_uid() = default;
        explicit constexpr
        CONSTRUCTOR entity_uid( i64 _id, u128 _uuid ) : id( _id ), uuid( _uuid ) {}
        explicit constexpr
        CONSTRUCTOR entity_uid( u128 _uuid ) : id(0), uuid( _uuid ) {}
        explicit constexpr
        CONSTRUCTOR entity_uid( i64 _id )
            : id(_id), uuid() { }
        explicit constexpr
        COPY_CONSTRUCTOR entity_uid( const t_self& arg )
            : id(arg.id), uuid(arg.uuid) { }
        COPY_CONSTRUCTOR entity_uid( const uid& arg )
            : id(arg.id), uuid(arg.uuid) { }

        explicit operator i64();

        PROC operator ==( t_self rhs ) -> bool
        {   return memory_same( this->uuid, rhs.uuid ); }

        PROC valid() -> bool
        {   auto empty = u128 {};
            return memory_different( this->uuid, empty );
        }

        PROC untyped_uid() -> uid
        {   return uid { id, uuid };
        }
    };

}
