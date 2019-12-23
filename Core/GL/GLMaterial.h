#ifndef GLMATERIAL_H
#define GLMATERIAL_H

#include "../Rendering/Material.h"

class GLMaterial : public Material
{
public:
    GLMaterial(const RefPtr<Texture>& texture, const Color& color);
};

#endif // GLMATERIAL_H
