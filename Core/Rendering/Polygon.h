#ifndef POLYGON_H
#define POLYGON_H

#include "../Global.h"
#include "Triangle.h"
#include "Material.h"

struct Polygon
{
    Vector<Triangle> triangles;
    RefPtr<Material> material;
};

#endif // POLYGON_H
