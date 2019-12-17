#include "Path.h"

Path::Path(const String& path_string)
    : std::experimental::filesystem::path(String::to_std_string(path_string))
{
}

