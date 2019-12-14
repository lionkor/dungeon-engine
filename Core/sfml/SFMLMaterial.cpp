#include "SFMLMaterial.h"
#include "SFMLTexture.h"
#include "SFMLBackend.h"


SFMLMaterial::SFMLMaterial(const RefPtr<Texture>& tex, const Color& col)
    : Material(std::move(tex), col)
{
}

sf::Texture SFMLMaterial::sf_texture()
{
}

sf::Color SFMLMaterial::sf_color()
{
    return to_sf_color(m_color);
}
