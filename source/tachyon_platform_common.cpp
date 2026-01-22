

namespace tyon
{
    PROC file_set_working_directory( fstring arg ) -> void
    {
        TYON_LOGF( "Changing working directory to: '{}'", fs::canonical( arg ).string() );
        fs::current_path( arg );
    }

}
