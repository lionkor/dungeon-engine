#include "SFMLTexture.h"
#include "../GenericResource.h"

SFMLTexture::SFMLTexture() {}

void SFMLTexture::load_from_file(const Path& path)
{
    ASSERT(m_texture);
    bool rc = m_texture->loadFromFile(path);
    ASSERT(rc);
}

void SFMLTexture::load_from_memory(const GenericResource& res)
{
    ASSERT(m_texture);
    bool rc = m_texture->loadFromMemory(res.data_as_void_ptr(), res.size());
    ASSERT(rc);
}
