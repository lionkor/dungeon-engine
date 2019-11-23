#ifndef SFMLRENDERABLE_H
#define SFMLRENDERABLE_H

#include "../Global.h"
#include "SFMLMaterial.h"

struct SFMLBufferInterval : public GUID
{
    SizeT index;
    SizeT count;
    SFMLMaterial material;
};

#endif // SFMLRENDERABLE_H
