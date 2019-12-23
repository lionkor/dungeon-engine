#include "SFMLMaterial.h"
#include "SFMLTexture.h"
#include "SFMLBackend.h"


SFMLMaterial::SFMLMaterial(const RefPtr<Texture>& tex, const Color& col)
    : Material(std::move(tex), nullptr, col)
{
    ASSERT(false); // we're also passing nullptr there, yikes
}

sf::Texture SFMLMaterial::sf_texture()
{
}

sf::Color SFMLMaterial::sf_color()
{
    return to_sf_color(m_color);
}
