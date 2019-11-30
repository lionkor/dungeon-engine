#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Global.h"
#include "Texture.h"
#include "Color.h"

class Material
{
public:
    Material();
    Material(const Texture&);
    Material(const Color&);
    Material(const Texture&, const Color&);
    virtual ~Material();

    virtual Texture& texture();
    virtual const Texture& texture() const;
    
    virtual void set_texture(const Texture&);
    
    virtual Color color() const;
    virtual void set_color(const Color& color);

protected:
    
    Texture m_texture;
    Color m_color;
};

#endif // MATERIAL_H
