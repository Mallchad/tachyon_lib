

namespace tyon
{

    PROC file_streamed_write( file* out_file, raw_pointer address, i64 size ) -> fresult
    {
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
        fresult result = false;
        try 
        {   result = fs::create_directories( arg );
        }
        catch ( std::exception& e ) { TYON_ERRORF( "An exception occured: '{}'", e.what() ); }
        return result;
    }

}
