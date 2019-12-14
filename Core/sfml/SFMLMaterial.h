#ifndef SFMLMATERIAL_H
#define SFMLMATERIAL_H

#include "../Global.h"
#include "../Rendering/Material.h"

class SFMLMaterial : public Material
{
public:
    SFMLMaterial(const RefPtr<Texture>&, const Color&);

    virtual sf::Texture sf_texture();
    virtual sf::Color   sf_color();

protected:
};

#endif // SFMLMATERIAL_H
