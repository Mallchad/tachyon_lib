#pragma once

namespace tyon
{
    // -- Asset Library --

    inline bool asset_function_stub( asset* arg ) { return false; }
    using asset_function = decltype( &asset_function_stub );

    enum class asset_type
    {
        none = 0,
        text = 1,
        svg = 2,
        svg_as_texture = 3
    };
    using e_asset = asset_type;

    struct asset_type_data
    {
        fstring name;
        e_asset type = asset_type::none;
        asset_function loader = &asset_function_stub;
        asset_function unloader =  &asset_function_stub;
    };

    struct asset
    {
        // File/Asset type
        e_asset type = asset_type::none;
        fstring name;
        file file_;
        void* data = nullptr;
        asset_function loader = &asset_function_stub;
        asset_function unloader = &asset_function_stub;
        fstring loader_name;
        time_date time_loaded;
        bool loaded = false;
    };

    struct asset_machine
    {
        array<fpath> search_paths;
        array<asset> assets;
        array<asset_type_data> asset_types;
        bool initialied;
    };

    void
    asset_machinery_init();

    PROC asset_enumerate_files() -> void;

    asset*
    asset_search( fstring filename, e_asset type );

    asset*
    asset_queue_load( fstring filename, e_asset type );

    void
    asset_machinery_register_type(
        fstring name,
        e_asset type,
        asset_function loader,
        asset_function unloader
        );


    bool
    asset_execute_loader( asset* arg );
}
