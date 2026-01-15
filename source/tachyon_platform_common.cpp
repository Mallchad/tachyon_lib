

namespace tyon
{
    PROC file_set_working_directory( fstring arg ) -> void
    {
        fs::current_path( arg );
    }

}
