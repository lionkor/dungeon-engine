#include "Texture.h"
#include "../IO/File.h"

Texture::Texture()
{
    
}

Texture::Texture(const Path& path)
{
    load_from_file(path);
}

Texture::Texture(const GenericResource& res)
{
    load_from_memory(res);
}

Texture::~Texture()
{
    delete m_pixels;
}

void Texture::load_from_file(const Path& path)
{
    ImageFile file(path);
    auto tex = file.create_texture();
    m_width = tex.m_width;
    m_height = tex.m_height;
    m_pixels = tex.m_pixels;
    tex.m_pixels = nullptr;
}

void Texture::load_from_memory(const GenericResource& res)
{
    NOTIMPL
}

SizeT Texture::width() const
{
    ASSERT(m_pixels != nullptr);
    return m_width;
}

void Texture::set_width(const SizeT& width)
{
    ASSERT(m_pixels != nullptr);
    m_width = width;
}

SizeT Texture::height() const
{
    ASSERT(m_pixels != nullptr);
    return m_height;
}

void Texture::set_height(const SizeT& height)
{
    ASSERT(m_pixels != nullptr);
    m_height = height;
}

Color& Texture::pixel_at(SizeT x, SizeT y)
{
    ASSERT(m_pixels != nullptr);
    ASSERT(x < m_width);
    ASSERT(x >= 0);
    ASSERT(y < m_height);
    ASSERT(y >= 0);
    //return m_pixels[x + y * m_width];
}

uchar* Texture::pixels()
{
    return m_pixels;
}

const uchar* Texture::pixels() const
{
    return m_pixels;
}
