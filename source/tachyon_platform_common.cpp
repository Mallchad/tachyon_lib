

namespace tyon
{
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
