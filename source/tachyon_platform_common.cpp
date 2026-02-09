

namespace tyon
{

    PROC file_streamed_write( file* out_file, raw_pointer address, i64 size ) -> fresult
    {
        PROFILE_SCOPE_FUNCTION();
        fresult result = true;
        // TODO: Need to change this to make / platform specific append
        // mode: read/write append binary
        FILE* file_ref = fopen( out_file->filename.c_str(), "a+b" );
        if (file_ref == nullptr)
        {   TYON_ERRORF( "Failed to open file: '{}'", out_file->filename );
            return false;
        }
        i64 written = fwrite( address, size, 1, file_ref );
        if (written < size)
        {   TYON_ERRORF( "Failed to write full content of file, size: {} written: {}",
            size, written );
            result = false;
        }
        else
        {   TYON_LOG( "Write {} bytes into filestream {}", written, out_file->filename );
        }
        fclose( file_ref );
        return result;
    }

    PROC file_streamed_read( file* arg, buffer* out_buffer, i64 max_size ) -> fresult
    {
        PROFILE_SCOPE_FUNCTION();
        if (arg == nullptr)
        {   return false; }
        if (out_buffer == nullptr)
        {   TYON_ERROR( "Passed nullptr to out_buffer " );
            return false;
        }

        fresult result = true;
        // TODO: Need to change this to make / platform specific append
        // mode: read/write binary
        FILE* file_ref = fopen( arg->filename.c_str(), "r+b" );
        if (file_ref == nullptr)
        {   TYON_ERRORF( "Failed to open file: '{}'", arg->filename );
            return false;
        }

        // Fill the buffer with some memory
        *out_buffer = {};
        out_buffer->data = memory_allocate_raw( max_size );
        out_buffer->size = max_size;

        // reset read/write pointer to stream poistion
        fseek( file_ref, arg->stream_readhead, SEEK_SET );
        // It's a success if anything was read at all, since we don't really assume file size
        i64 bytes_read = fread( out_buffer->data, max_size, 1, file_ref );
        if (bytes_read <= 0)
        {   TYON_LOGF( "Could not read any more data in file '{}'", arg->filename );
            TYON_LOG( "Likely reached end-of-file." );
            result = false;
        }
        else
        {   TYON_LOG( "Read {} bytes from filestream '{}'", bytes_read, arg->filename );
        }
        fclose( file_ref );
        return result;
    }

    PROC file_set_working_directory( fstring arg ) -> void
    {
        fstring absolute_path = fs::canonical( arg ).string();
        if (g_logger)
        {   TYON_LOGF( "[Tachyon]    Changing working directory to: '{}'", absolute_path );
        }
        else
        {   fmt::print( "[Tachyon]    Changing working directory to: '{}'", absolute_path );
        }
        fs::current_path( arg );
    }

    PROC file_create_directory( fstring arg )  -> fresult
    {
        PROFILE_SCOPE_FUNCTION();
        fresult result = false;
        try 
        {   result = fs::create_directories( arg );
        }
        catch ( std::exception& e ) { TYON_ERRORF( "An exception occured: '{}'", e.what() ); }
        return result;
    }

}
