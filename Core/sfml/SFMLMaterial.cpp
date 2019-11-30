#include "SFMLMaterial.h"
#include "SFMLTexture.h"


SFMLMaterial::SFMLMaterial(const RefPtr<Texture>& tex, Color color)
    : m_texture(nullptr), m_color({ color.r, color.g, color.b, color.a })
{
    if (tex.is_not_null())
    {
        RawPtr<SFMLTexture> ptr = reinterpret_cast<SFMLTexture*>(tex.get());
        m_texture = ptr->sf_texture();
    }
}

bool SFMLMaterial::has_texture() const { NOTIMPL }

RefPtr<Texture> SFMLMaterial::texture()
{
    NOTIMPL
}

const RefPtr<Texture> SFMLMaterial::texture() const { NOTIMPL }

void SFMLMaterial::set_texture(const RefPtr<Texture>& texture) { NOTIMPL }

void SFMLMaterial::set_texture(const Path& path) { NOTIMPL }

void SFMLMaterial::set_texture(const GenericResource& res) { NOTIMPL }

Color SFMLMaterial::color()
{
    return Color(m_color.r, m_color.g, m_color.b, m_color.a);
}

void SFMLMaterial::set_color(const Color& color)
{
    m_color = sf::Color(color.r, color.g, color.b, color.a);
}

sf::Color SFMLMaterial::sf_color() { return m_color; }
