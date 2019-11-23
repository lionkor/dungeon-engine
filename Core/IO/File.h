#ifndef FILE_H
#define FILE_H

#include <fstream>

#include "../Global.h"
#include "Path.h"

class File : public std::fstream
{
public:
    File(const Path& path);
    ~File();
    
    template<typename _T>
    void write(const _T& value)
    {
        ASSERT(is_open());
        
    }
};

#endif // FILE_H
