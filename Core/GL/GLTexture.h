#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "../Global.h"
#include "../GenericResource.h"
#include "../IO/Path.h"
#include "../Rendering/Texture.h"
#include <gli/gli.hpp>

class GLTexture : public Texture
{
public:
    GLTexture(const Path& path);
    GLTexture(const GenericResource& res);

    virtual void  load_from_file(const Path&) override;
    virtual void  load_from_memory(const GenericResource&) override;
    virtual SizeT width() const override;
    virtual SizeT height() const override;
    virtual Color pixel_at(SizeT x, SizeT y) override;
    virtual void  set_pixel_at(SizeT x, SizeT y, const Color& col) override;
};

#endif // GLTEXTURE_H
