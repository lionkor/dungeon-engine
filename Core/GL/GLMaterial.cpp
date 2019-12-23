#include "GLMaterial.h"

GLMaterial::GLMaterial(const RefPtr<Texture>& texture, const Color& color)
    : Material(texture, color)
{
    verbose(__PRETTY_FUNCTION__);
}
