#include "Material.h"
#include "../Application.h"

Material::Material()
{
    
}

Material::Material(const Texture& tex)
    : m_texture(tex)
{
}

Material::Material(const Color& col)
    : m_color(col)
{
    
}

Material::Material(const Texture& tex, const Color& col)
    : m_texture(tex), m_color(col)
{
    
}

Material::~Material()
{
    
}

Texture& Material::texture()
{
    return m_texture;
}

const Texture& Material::texture() const
{
    return m_texture;
}

void Material::set_texture(const Texture& tex)
{
    m_texture = tex;
}

Color Material::color() const
{
    return m_color;
}

void Material::set_color(const Color& color)
{
    m_color = color;
}

