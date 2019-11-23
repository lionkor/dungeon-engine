#ifndef COLOR_H
#define COLOR_H

#include "../Global.h"

struct Color
{
    Color(uchar r, uchar g, uchar b, uchar a)
        : r(r), g(g), b(b), a(a)
    {}
    
    uchar r, g, b, a;
};

#endif // COLOR_H
