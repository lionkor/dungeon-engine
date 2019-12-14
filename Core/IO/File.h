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
        NOTIMPL
    }
};

class Texture;

class ImageFile : public File
{
public:
    ImageFile(const Path& path);

    RefPtr<Texture> create_texture();

protected:
    Path m_path;
};

#endif // FILE_H
