
#include "include_tachyon_lib_core.h"

#if (REFLECTION_PLATFORM_LINUX)

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

namespace platform
{
    #include <uuid/uuid.h>
}

namespace fs = std::filesystem;

namespace tyon
{

    auto file_self_directory() -> fpath
    {
        fpath result;
        result = fs::canonical( "/proc/self/exe" );
        result = result.parent_path();
        return result;
    }

    auto file_self_filename() -> fpath
    {
        fpath result;
        result = fs::canonical( "/proc/self/exe" );
        return result;
    }

    fresult
    file_write_binary( file* arg )
    {
        fstring filename = arg->filename.string();
        bool write_ok = false;
        /** O_DSYNC - Don't return from the function until the data AND metadata is actually written.
            O_DIRECT - minimize caching effects, needs to be paired with O_SYNC or DSYNC.
            O_CREAT - create file if it doesn't exist already
            0664 - provide octal rw-rw---- permissions. read/write for group and owner*/
        i32 fd = open( filename.c_str(), O_CREAT | O_RDWR | O_DIRECT | O_DSYNC, 0664 );
        if (fd == -1)
        {   TYON_ERRORF( "Failde to open file for writing '{}'", arg->filename.string() );
            return false;
        }

        u32 prot_flags = (PROT_READ | PROT_WRITE);
        // MAP_SHARED is mandatory for file writes.
        u32 map_flags = (MAP_SHARED | MAP_POPULATE);
        u64 map_size = arg->memory.size;

        {
            PROFILE_SCOPE( "File Map All" );
            // Can't get effective error vlaues from ftruncate for some reason
            i32 resize_ok = ftruncate( fd, arg->memory.size );
            if (resize_ok != 0)
            {   TYON_ERRORF( "Failed to resize file when trying to write file data '{}'",
                            arg->filename.string() );
                close( fd );
                return false;
            }
            void *address = mmap( nullptr, map_size, prot_flags, map_flags, fd, 0x0 );
            if (address != reinterpret_cast<void*>(-1))
            {
                PROFILE_SCOPE( "File Map Copy" );
                memory_copy_raw( address, arg->memory.data, arg->memory.size );
                munmap( address, map_size );
            }
            else 
            {   TYON_ERRORF( "Failed to map file for reading '{}'", arg->filename.string() );
                close( fd );
                return false;
            }
            close( fd );
        }
        TYON_LOGF( "Write file '{}' occupying {} logical bytes", arg->filename, arg->memory.size );
        return true;
    }

    fresult
    file_write_binary_posix( file* arg )
    {
        fstring filename = arg->filename.string();

        // Overwrite pre-existing file completely
        i32 fd = open( filename.c_str(), 0x0, O_WRONLY );
        ERROR_GUARD( fd > 0, "Failed to open file" );
        u64 bytes_written = write( fd, arg->memory.data, arg->memory.size );
        bool write_ok = (i32(bytes_written) >= arg->memory.size);

        // Cleanup
        close( fd );
        if (write_ok)
        { TYON_LOG( fmt::format( "Wrote binary file '{}'", arg->filename ) ); }
        else
        { TYON_LOG( "Failed to write binary file '{}'", arg->filename  ); }
        ERROR_GUARD( write_ok, "File wrote less than full data or failed" );


        return write_ok;
    }

    PROC file_home_directory() -> fstring
    {
        fstring env_name = "HOME";
        char* home_path = getenv( env_name.c_str() );
        if (home_path == nullptr)
        {   TYON_BASE_ERROR(
                "Tachyon Linux", "Error reading home home directory environment variable" );
            return {};
        }
        fstring result = fs::canonical( home_path ).string();
        return result;
    }

    /* uuid v4 */
    u128
    uuid_generate()
    {
        // TODO: Maybe check '/proc/sys/kernel/random/entropy_avail' before stalling on entropy check...
        platform::uuid_t generated;
        platform::uuid_generate( generated );
        u128 result = {};
        u128 empty = {};
        memory_copy_unsafe<u128>( &result, &generated, 1 );
        ERROR_GUARD( memory_different( result, empty ),
                     "Something is wrong if this a UUID comes back null" );

        return result;
    }

    fresult
    thread_self_name( fstring name )
    {
        pthread_setname_np( pthread_self(), name.c_str() );
        if ((name.size() + 1) >= 16)
        {
            TYON_ERROR(
                "pthread doesn't support names large than 16 including the null terminator" );
            return false;
        }
        return true;
    }

    fresult
    thread_self_background_priority()
    {
        bool result;
#if (REFLECTION_PLATFORM_LINUX)
        errno = 0;
        nice(19);
        result = bool(errno);

#endif // REFLECTION_COMPILER_CLANG
        return result;
    }

    system_info
    system_info_fetch()
    {
        system_info result = {};
        return result;
    }

}

#endif // REFLECTION_PLATFORM_LINUX
