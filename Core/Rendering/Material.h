#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Global.h"
#include "Texture.h"
#include "Color.h"

class Material
{
public:
    Material();
    virtual ~Material();

    virtual bool has_texture() const = 0;
    
    virtual RefPtr<Texture> texture() = 0;
    virtual const RefPtr<Texture> texture() const = 0;
    
    virtual void set_texture(const RefPtr<Texture>& texture) = 0;
    virtual void set_texture(const Path& path) = 0;
    virtual void set_texture(const GenericResource& res) = 0;
    
    virtual Color color() = 0;
    virtual void set_color(const Color& color) = 0;

protected:
};

#endif // MATERIAL_H
