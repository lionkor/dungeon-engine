#ifndef SFMLMATERIAL_H
#define SFMLMATERIAL_H

#include "../Global.h"
#include "../Rendering/Material.h"

class SFMLMaterial : public Material
{
public:
    SFMLMaterial();
    
    virtual bool has_texture() const override;
    virtual RefPtr<Texture> texture() override;
    virtual const RefPtr<Texture> texture() const override;
    virtual void set_texture(const RefPtr<Texture>& texture) override;
    virtual void set_texture(const Path& path) override;
    virtual void set_texture(const GenericResource& res) override;
    virtual Color color() override;
    virtual void set_color(const Color& color) override;
    
    virtual sf::Color sf_color();
protected:
    sf::Texture m_texture;
    sf::Color m_color;
};

#endif // SFMLMATERIAL_H
