#ifndef SPRITE_H
#define SPRITE_H

#include "../Global.h"
#include "Material.h"
#include "Primitives.h"

struct Sprite
{
    Sprite() : material(nullptr), rectangle({ { 0, 0 }, { 0, 0 } }) {}
    Sprite(RefPtr<Material> mat, Rectangle rect) : material(mat), rectangle(rect) {}

    RefPtr<Material> material;
    Rectangle rectangle;
};

#endif // SPRITE_H
