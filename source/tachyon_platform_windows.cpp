
#include "include_tachyon_lib_core.h"

#if (REFLECTION_PLATFORM_WINDOWS)

namespace fs = std::filesystem;

namespace tyon
{

    auto file_self_directory() -> fpath
    {
        fpath result;
        wchar_t buffer[1024];
        GetModuleFileNameW(NULL, buffer, MAX_PATH);
        result = fs::canonical( buffer );
        result = result.parent_path();
        return result;
    }

    auto file_self_filename() -> fpath
    {
        fpath result;
        wchar_t buffer[1024];
        GetModuleFileNameW(NULL, buffer, MAX_PATH);
        result = fs::canonical( buffer );
        return result;
    }

    fresult
    file_write_binary( file* arg )
    { return file_write_binary_stdlib( arg ); }

    PROC file_home_directory() -> fstring
    {
        TYON_ERROR( "File home directory not implimented on Windows yet" );
        return "";
    }

    u128
    uuid_generate()
    {
        u128 result;
        UUID generated;
        UuidCreate( &generated );
        memory_copy_unsafe<u128>( &result, &generated, 1 );
        ERROR_GUARD( memory_same_raw( &result, &generated, sizeof(u128) ), "Something is wrong if this a UUID comes back null" );

        return result;
    }

    // Thread names aren't supported on Windows but there are various markup for programs
    // So we must find a way to give it a name anyway.
    fresult
    thread_self_name( fstring name )
    {
        // pthread_setname_np(pthread_self(), "tyon_render");
        return true;
    }


    // This is not implimented on windows at all
    fresult
    thread_self_background_priority()
    {
        // Sets the priority for the whole process
        // SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_BEGIN);
        bool result = false;

        HANDLE thread;
        GetThreadId( &thread );
        // Needs to have the correct thread security context set at thread creation
        // TODO(mallcad): Replace std::thread implimentation with custom wrapper.
        BOOL error = SetThreadPriority( thread, THREAD_PRIORITY_LOWEST );
        result = error;
        // if (error == 0) {
        //     tyon_log("Failed to set thread priority"); log_flush();
        //     *(char*)0 = 0; // Crash
        // }

        return result;
    }

    system_info
    system_info_fetch()
    {
        system_info result = {};

        result.system_name = "Windows";

        proc_LogicalProcessorInformationEx dyn_GetLogicalProcessorInformationEx = nullptr;
        raw_pointer info_list = memory_allocate<SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX>( 1024 );

        // Get/Call dynamic function from system
        // HMODULE kernel = GetModuleHandle( "kernel32.dll" );
        // if (kernel == NULL)
        // {
        //     tyon_log_error( "Failed to get kernel32 handle" );
        // }
        // tyon_log( "getting proc address" );
        // GetLogicalProcessorInformationEx =
        //     reinterpret_cast<proc_LogicalProcessorInformationEx>(GetProcAddress( kernel , "GetLogicalProcessorInformationEx"));
        // if (dyn_GetLogicalProcessorInformationEx == nullptr)
        // {
        //     tyon_log_error("GetLogicalProcessorInformationEx symbol could not be loaded ");
        //     return result;
        // }
        DWORD _info_size = 1024* sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX);
        bool fetch_ok = GetLogicalProcessorInformationEx(
            RelationAll, info_list,  &_info_size
            );
        if (fetch_ok == false)
        {
            info_list = memory_allocate<SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX>( 8912 );
        }
        _info_size = 8912 * sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX);
        fetch_ok = GetLogicalProcessorInformationEx(
            RelationAll, info_list, &_info_size
            );
        if (fetch_ok == false)
        {
            TYON_BASE_ERROR( "Tachyon Windows", "Failed to processor information twice." );
            return result;
        }

        // Okay we can start working for real
        cpu_info& cpu = result.cpu;
        SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX x_info;
        LOGICAL_PROCESSOR_RELATIONSHIP type;
        cpu_core_info core;
        i32 valid_count = 0;
        raw_pointer head = info_list;
        raw_pointer info_list_end = info_list + (sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX) * 8912);
        std::bitset<64> mask;

        for (int i=0; i < 2048; ++i)
        {
            x_info = head.as<SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX>();
            core = {};
            type = x_info.Relationship;
            head += x_info.Size;

            if (head.data >= info_list_end) { break; }
            if (x_info.Size == 0) continue;
            valid_count++;

            switch (type)
            {
            case RelationProcessorCore:
            {
                core.hyperthreading_enabled = (x_info.Processor.Flags == LTP_PC_SMT);
                cpu.hyperthreading_enabled &= core.hyperthreading_enabled;

                // Just assume this is two on normal systems because we don't know better.
                i32 cores_added = (1 + core.hyperthreading_enabled);
                cpu.physical_core_count++;
                cpu.virtual_core_count += cores_added;

                if (core.hyperthreading_enabled == false)
                { cpu.physical_cores.push_tail( core ); }
                break;
            }
            case RelationNumaNode:
                // Non-NUMA systems report a single record of this type.
                cpu.numa_node_count++;
                break;
            case RelationCache:
                if (x_info.Cache.Level == 1) { ++ cpu.l1_cache_count; }
                else if (x_info.Cache.Level == 2) { ++ cpu.l2_cache_count; }
                else if (x_info.Cache.Level == 3) { ++ cpu.l3_cache_count; }
                else if (x_info.Cache.Level == 4) { ++ cpu.l4_cache_count; }

                mask = x_info.Cache.GroupMask.Mask;
                for (int i_bit=0; i_bit < mask.size(); ++i_bit)
                {
                    if (mask[i_bit])
                    {}
                }

                break;
            case RelationProcessorPackage:
                // Logical processors share a physical package.
                cpu.package_count++;
                break;

            default:
                break;
            }
        }

        struct cpuid_return
        {
            i32 a;
            i32 b;
            i32 c;
            i32 d;
        };
        cpuid_return read;
        raw_pointer cpuid_data = &read;
        __cpuid( cpuid_data, 0x0 );

        i32 highest_function_id = read.a;
        cpuid_data = memory_allocate<cpuid_return>( highest_function_id + 10 );
        for (int i=0; i <= highest_function_id; ++i)
        {
            raw_pointer r_head = cpuid_data + (i* 16);
            __cpuidex( r_head, i, 0x0 );
        }
        char vendor_string[20] = {};
        raw_pointer w_vendor = vendor_string;
        memory_copy_raw( w_vendor + 0, cpuid_data+ 4, 4 );
        memory_copy_raw( w_vendor+ 4, cpuid_data+ 12, 4 );
        memory_copy_raw( w_vendor+ 8, cpuid_data+ 8, 4 );

        vendor_string[19] = 0;
        cpu.vendor = vendor_string;

        // Try to get long form CPU Brand string

        // Get the extra cpuid data
        i32 extra_start = 0x80000000;
        raw_pointer cpuid_extra = &read;
        // Get the highest read address
        __cpuid( cpuid_extra, 0x80000000 );
        i32 highest_extra_id = read.a;
        i32 extra_size = (highest_extra_id - extra_start);

        cpuid_extra = memory_allocate<cpuid_return>( extra_size + 10 );
        for (int i=0; i <= extra_size; ++i)
        {
            raw_pointer r_head = cpuid_extra + (i* 16);
            __cpuidex( r_head, (extra_start + i), 0x0 );
        }

        char brand_string[64] = {};
        raw_pointer w_brand = brand_string;

        if (highest_extra_id > 0x80000004)
        {
            memory_copy_raw( w_brand  +0, cpuid_extra +32, 16 );
            memory_copy_raw( w_brand +16, cpuid_extra +48, 16 );
            memory_copy_raw( w_brand +32, cpuid_extra +64, 16 );
        }
        brand_string[63] = 0;
        cpu.name = brand_string;

        if (cpu.package_count > 1)
        {
            TYON_BASE_ERROR( "Tachyon Windows",
                "More than 1 package count is not supported for "
                "diagnostics yet, system information will probably be incorrect" );
        }

        return result;
    }

}

#endif // REFLECTION_PLATFORM_WINDOWS
