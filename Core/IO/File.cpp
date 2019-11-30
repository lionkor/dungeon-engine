#include "File.h"
#include "../Rendering/Texture.h"

File::File(const Path& path) : std::fstream(path) {}

File::~File() {}

ImageFile::ImageFile(const Path& path) : File(path), m_image()
{
    m_image.loadFromFile(path.string());
}

Texture ImageFile::create_texture()
{
    Texture tex;
    tex.m_width = m_image.getSize().x;
    tex.m_height = m_image.getSize().y;
    SizeT count = tex.m_width * tex.m_height;
    tex.m_pixels = new uchar[count * 4];
    std::memcpy(tex.m_pixels, m_image.getPixelsPtr(), count * 4);
    return tex;
}
