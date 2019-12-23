#include "GLMaterial.h"

GLMaterial::GLMaterial(const RefPtr<Texture>& texture, const RefPtr<Shader>& shader,
                       const Color& color)
    : Material(texture, shader, color)
{
    verbose(__PRETTY_FUNCTION__);
}
