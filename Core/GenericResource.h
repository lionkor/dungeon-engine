#ifndef GENERICRESOURCE_H
#define GENERICRESOURCE_H

#include "Global.h"
#include "IO/Path.h"
#include "Rendering/Texture.h"

// FIXME: Add a hint to the type of data(?)
class GenericResource
{
public:
    GenericResource();
    explicit GenericResource(const Path& path);
    virtual ~GenericResource();

    // FIXME: Keep deleted?
    GenericResource(const GenericResource& res) = delete;
    GenericResource(GenericResource&& res)      = delete;

    virtual void               load_async();
    virtual void               load();
    virtual void               unload();
    virtual void               reload();
    virtual RawPtr<void>       data_as_void_ptr();
    virtual const RawPtr<void> data_as_void_ptr() const;
    virtual SizeT              size() const;

protected:
    RawPtr<void> m_data;
    SizeT        m_size;
    Path         m_path;
    bool         m_is_loaded { false };
};

#endif // GENERICRESOURCE_H
