#include "SFMLTexture.h"
#include "SFMLBackend.h"
#include "../GenericResource.h"

void SFMLTexture::load_from_file(const Path& path)
{
    ASSERT(m_image.is_not_null());
    bool rc = m_image->loadFromFile(path);
    ASSERT(rc);
}

void SFMLTexture::load_from_memory(const GenericResource& res)
{
    ASSERT(m_image.is_not_null());
    bool rc = m_image->loadFromMemory(res.data_as_void_ptr(), res.size());
    ASSERT(rc);
}

RefPtr<sf::Texture> SFMLTexture::sf_texture() const
{
    auto tex = RefPtr<sf::Texture>::make();
    bool rc  = tex->loadFromImage(*m_image);
    ASSERT(rc);
    return tex;
}

SizeT SFMLTexture::width() const
{
    return m_image->getSize().x;
}

SizeT SFMLTexture::height() const
{
    return m_image->getSize().y;
}

Color SFMLTexture::pixel_at(SizeT x, SizeT y)
{
    auto tmp = m_image->getPixel(x, y);
    return Color(tmp.r, tmp.g, tmp.b, tmp.a);
}

void SFMLTexture::set_pixel_at(SizeT x, SizeT y, const Color& col)
{
    m_image->setPixel(x, y, to_sf_color(col));
}

SFMLTexture::SFMLTexture(const Path& path) : m_image(RefPtr<sf::Image>::make())
{
    load_from_file(path);
}

SFMLTexture::SFMLTexture(const GenericResource& res) : m_image(RefPtr<sf::Image>::make())
{
    load_from_memory(res);
}
