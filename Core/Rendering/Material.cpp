#include "Material.h"
#include "../Application.h"
#include "../sfml/SFMLMaterial.h"
#include "../GL/GLMaterial.h"

Material::Material(const RefPtr<Texture>& tex, const RefPtr<Shader>& shader,
                   const Color& col)
    : m_texture(tex), m_color(col), m_shader(shader)
{
    // FIXME: Split this up?
    m_shader->load();
    m_shader->compile();
}

Material* new_sfml_material(const RefPtr<Texture>& tex, const RefPtr<Shader>& shader,
                            const Color& col)
{
    // NOTIMPL because we aren't capable of using or passing shaders here.
    NOTIMPL;
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

RefPtr<Shader> Material::shader()
{
    return m_shader;
}

const RefPtr<Shader> Material::shader() const
{
    return m_shader;
}

Color Material::color() const
{
    return m_color;
}

void Material::set_color(const Color& color)
{
    m_color = color;
}

Material* new_gl_material(const RefPtr<Texture>& tex, const RefPtr<Shader>& shader,
                          const Color& col)
{
    return new GLMaterial(tex, shader, col);
}
