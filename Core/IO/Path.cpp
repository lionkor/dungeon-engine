#include "Path.h"

Path::Path(const StringView& path_string)
    : std::filesystem::path(String::to_std_string(path_string))
{
}

Path::Path(const String& path_string)
    : std::filesystem::path(String::to_std_string(path_string))
{
}
