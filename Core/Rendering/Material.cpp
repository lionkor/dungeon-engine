#include "Material.h"
#include "../Application.h"
#include "../sfml/SFMLMaterial.h"
#include "../GL/GLMaterial.h"

Material::Material(const RefPtr<Texture>& tex, const Color& col)
    : m_texture(tex), m_color(col)
{
}

Material* new_sfml_material(const RefPtr<Texture>& tex, const Color& col)
{
    return new SFMLMaterial(tex, col);
}

Material::~Material()
{
}

RefPtr<Texture> Material::texture()
{
    return m_texture;
}

const RefPtr<Texture> Material::texture() const
{
    return m_texture;
}

Color Material::color() const
{
    return m_color;
}

void Material::set_color(const Color& color)
{
    m_color = color;
}

Material* new_gl_material(const RefPtr<Texture>& tex, const Color& col)
{
    return new GLMaterial(tex, col);
}
