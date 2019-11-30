#ifndef SFMLRENDERABLE_H
#define SFMLRENDERABLE_H

#include "../Global.h"
#include "../Rendering/Material.h"

struct SFMLBufferInterval : public GUID
{
    SFMLBufferInterval(SizeT index, SizeT count, Material mat)
        : index(index), count(count), material(mat)
    {
    }
    SizeT index;
    SizeT count;
    Material material;
};

#endif // SFMLRENDERABLE_H
