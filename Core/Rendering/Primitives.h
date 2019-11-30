#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Global.h"
#include "Material.h"

struct Triangle
{
    vec2 points[3];
};

struct Rectangle
{
    vec2 position;
    vec2 size;
};

struct Polygon
{
    Vector<Triangle> triangles;
    RefPtr<Material> material;
};

#endif // TRIANGLE_H
