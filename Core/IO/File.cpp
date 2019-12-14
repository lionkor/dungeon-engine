#include "File.h"
#include "../Rendering/Texture.h"

File::File(const Path& path) : std::fstream(path)
{
}

File::~File()
{
}

ImageFile::ImageFile(const Path& path) : File(path), m_path(path)
{
}

RefPtr<Texture> ImageFile::create_texture()
{
    auto tex = Texture::construct(m_path);
    return tex;
}
