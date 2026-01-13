
#pragma once

namespace tyon
{
// -- Resource System --

using proc_resource_destroy = void();

/** Scoped generic resource management container
 *
 * This is a crude attempt to solve resource management in a way that isn't
 * restricted to one-struct per resource semantics. Constructors,
 * destructors, or otherwise.
 *
 * The method uses arena bound resource lifetimes. Essentially every resource
 * is bound to an arena. And it can either be freed from the arena manually
 * or be cleanuped up when it goes out of scope. */
struct resource_arena
{
    using cleanup_delegate = generic_procedure<proc_resource_destroy>;

    uid id;
    // The resource_arena this area belongs to. This arena will die with its parent.
    uid parent;
    array<cleanup_delegate> destroy_stack;

    // CONSTRUCTOR resource_arena() = delete;

    PROC push_cleanup( cleanup_delegate arg ) -> void;
    PROC run_cleanup() -> void;
    DESTRUCTOR ~resource_arena();
};

}
