#include "GLTexture.h"

GLTexture::GLTexture(const Path& path)
{
}

GLTexture::GLTexture(const GenericResource& res)
{
    NOTIMPL
}

void GLTexture::load_from_file(const Path&)
{
}

void GLTexture::load_from_memory(const GenericResource&)
{
}

SizeT GLTexture::width() const
{
}

SizeT GLTexture::height() const
{
}

Color GLTexture::pixel_at(SizeT x, SizeT y)
{
}

void GLTexture::set_pixel_at(SizeT x, SizeT y, const Color& col)
{
}
