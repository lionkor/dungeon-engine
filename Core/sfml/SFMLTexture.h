#ifndef SFMLTEXTURE_H
#define SFMLTEXTURE_H

#include "../Global.h"
#include "../Rendering/Texture.h"

class SFMLTexture : public Texture
{
public:
    SFMLTexture(const Path&);
    SFMLTexture(const GenericResource&);

    virtual void load_from_file(const Path& path) override;
    virtual void load_from_memory(const GenericResource& res) override;

    RefPtr<sf::Texture> sf_texture() const;

    virtual SizeT width() const override;
    virtual SizeT height() const override;

    virtual Color pixel_at(SizeT x, SizeT y) override;
    virtual void  set_pixel_at(SizeT x, SizeT y, const Color& col) override;

protected:
    RefPtr<sf::Image> m_image;
};

#endif // SFMLTEXTURE_H
