#ifndef PATH_H
#define PATH_H

#include "../Global.h"

class Path : public std::experimental::filesystem::path
{
public:
    Path(const String& path_string);

private:
};

#endif // PATH_H
