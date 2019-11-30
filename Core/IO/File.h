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

    Texture create_texture();

protected:
    sf::Image m_image;
};

#endif // FILE_H
