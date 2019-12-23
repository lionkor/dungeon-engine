#ifndef SPRITE_H
#define SPRITE_H

#include "../Global.h"
#include "Material.h"
#include "Primitives.h"

struct Sprite : public GUID
{
    Sprite(RefPtr<Material> mat, Rectangle rect) : material(mat), rectangle(rect) {}

    Sprite(const Path& texture_path, StringView shader_name, Rectangle rect,
           const Color& color = Color())
        : material(Material::construct(Texture::construct(texture_path),
                                       Shader::construct(shader_name), color)),
          rectangle(rect)
    {
    }

    RefPtr<Material> material;
    Rectangle        rectangle;
};

#endif // SPRITE_H
