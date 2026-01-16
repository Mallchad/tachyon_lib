
#pragma once


namespace tyon
{

    // -- Platform Library --

    enum class processor_core : u32
    {
        none            = 0,
        any             = 1,
        cpu             = 2,
        cpu__efficiency = 3,
        gpu             = 4
    };
    using e_processor_core = processor_core;

    struct cpu_cache_info
    {
        i32 cache_level = 0;
        i32 size_byte = 0;
        i32 average_latency = 0;
        i32 alignment = 0;
    };

    struct cpu_core_info
    {
        i32 id = -1;
        i32 frequency = 0;
        i32 frequency_limit_min = 0;
        i32 frequency_limit_max = 0;
        /** Highest and lowest observed frequency taking into account
         * measurements from transients and turbo */
        i32 frequency_lowest = 0;
        i32 frequency_peak = 0;
        i32 voltage_limit_min = 0;
        i32 voltage_limit_max = 0;
        /** Highest and lowest observed stable voltage varies depending on
         * conditions and drivers */
        i32 voltage_limit_lowest = 0;
        i32 voltage_limit_peak = 0;
        i32 processor_group = 0;
        // Hyper-threading can be enabled/disabled per core
        bool hyperthreading_enabled = false;
        i32 l1_cache_count = 0;
        i32 l2_cache_count = 0;
        i32 l3_cache_count = 0;
        i32 l4_cache_count = 0;
        array<cpu_cache_info> caches;
        i32 theoretical_throughput_gflops = 0;
    };

    struct numa_node_info
    {
    };

    struct cpu_info
    {
        fstring name = "Unknown";
        fstring sku = "Unknown";
        fstring vendor = "Unknown";
        fstring architecture = "Unknown";
        array<cpu_core_info> physical_cores;
        i32 physical_core_count = 0;
        i32 virtual_core_count = 0;
        i32 package_count = 0;
        i32 numa_node_count = 0;
        i32 l1_cache_count = 0;
        i32 l2_cache_count = 0;
        i32 l3_cache_count = 0;
        i32 l4_cache_count = 0;
        i32 tdp_watts = 0;
        bool hyperthreading_enabled = false;
        bool hyperthreading_supported = false;
        // extension_flags
    };

    enum class memory_type : u32
    {
        none = 0,
        any = 1,
        ddr1,
        ddr2,
        ddr3
        };
    using e_memory = memory_type;

    struct memory_info
    {
        e_memory type = memory_type::none;
        i32 size_bytes = 0;
        i32 channels = 0;
        i32 frequency = 0;
        i32 frequency_limit_min = 0;
        i32 frequency_limit_max = 0;
        /** Highest and lowest observed frequency taking into account
         * measurements from transients and turbo */
        i32 frequency_lowest = 0;
        i32 frequency_peak = 0;
        i32 processor_group = 0;
    };

    struct system_info
    {
        fstring system_name = "Uknown";
        cpu_info cpu;
        memory_info memory;
    };

    fresult
    FUNCTION test_little_endian();

    fpath
    file_self_directory();

    fpath
    file_self_filename();

    fresult
    file_open( file* arg );

    PROC file_set_working_directory( fstring arg ) -> void;

    u128
    uuid_generate();

    system_info
    system_info_fetch();

    PROC file_home_directory() -> fstring;

}
