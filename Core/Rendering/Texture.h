#ifndef TEXTURE_H
#define TEXTURE_H

#include "../Global.h"
#include "../IO/Path.h"
#include "Color.h"

class GenericResource;

class Texture : public GUID
{
public:
    friend class ImageFile;
    
    Texture();
    Texture(const Path&);
    Texture(const GenericResource&);
    virtual ~Texture();

    virtual void load_from_file(const Path&);
    virtual void load_from_memory(const GenericResource&);

    SizeT width() const;
    void set_width(const SizeT& width);

    SizeT height() const;
    void set_height(const SizeT& height);

    Color& pixel_at(SizeT x, SizeT y);
    
    uchar* pixels();
    const uchar* pixels() const;

protected:
    SizeT m_width { 0 };
    SizeT m_height { 0 };
    uchar* m_pixels { nullptr };
};


#endif // TEXTURE_H
