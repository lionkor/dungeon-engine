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
    Rectangle(float x, float y, float w, float h) : position(x, y), size(w, h) {}
    Rectangle(const vec2& pos, const vec2& size) : position(pos), size(size) {}
    vec2 position;
    vec2 size;
};

struct Polygon
{
    Vector<Triangle> triangles;
    RefPtr<Material> material;
};

#endif // TRIANGLE_H
