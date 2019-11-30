#ifndef COLOR_H
#define COLOR_H

#include "../Global.h"

struct Color
{
    Color() : r(255), g(0), b(255), a(255) {}

    Color(uchar r, uchar g, uchar b, uchar a) : r(r), g(g), b(b), a(a) {}

    uchar r, g, b, a;
};

#endif // COLOR_H
