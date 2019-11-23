#ifndef PATH_H
#define PATH_H

#include "Global.h"

class Path : public std::filesystem::path
{
public:
    Path(const String& path_string);
private:
};

#endif // PATH_H
