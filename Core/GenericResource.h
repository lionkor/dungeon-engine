#ifndef GENERICRESOURCE_H
#define GENERICRESOURCE_H

#include "Global.h"
#include "Path.h"
#include "Texture.h"

class GenericResource
{
public:
    GenericResource(const Path& path);
    virtual ~GenericResource();
    
    // FIXME: Keep deleted?
    GenericResource(const GenericResource& res) = delete;
    GenericResource(GenericResource&& res) = delete;
    
    virtual void load_async() = 0;
    virtual void load() = 0;
    virtual RawPtr<void> data_as_void_ptr() = 0;
    virtual const RawPtr<void> data_as_void_ptr() const = 0;
};

#endif // GENERICRESOURCE_H
