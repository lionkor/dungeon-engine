#ifndef SFMLRENDERABLE_H
#define SFMLRENDERABLE_H

#include "../Global.h"
#include "SFMLMaterial.h"

struct SFMLBufferInterval : public GUID
{
    SFMLBufferInterval(SizeT index, SizeT count, SFMLMaterial mat)
        : index(index), count(count), material(mat)
    {
    }
    SizeT index;
    SizeT count;
    SFMLMaterial material;
};

#endif // SFMLRENDERABLE_H
