#ifndef TEXTURE_H
#define TEXTURE_H

#include "Global.h"
#include "Path.h"

class GenericResource;

class Texture : public GUID
{
public:
    Texture();
    virtual ~Texture();
    
    virtual OwnPtr<Texture> load_from_file(const Path& path) = 0;
    virtual OwnPtr<Texture> load_from_memory(const GenericResource& res) = 0;
protected:
};

#endif // TEXTURE_H
