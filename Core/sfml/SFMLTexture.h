#ifndef SFMLTEXTURE_H
#define SFMLTEXTURE_H

#include "../Global.h"
#include "../Texture.h"

class SFMLTexture : public Texture
{
public:
    SFMLTexture();
    
    virtual void load_from_file(const Path& path) override;
    virtual void load_from_memory(const GenericResource& res) override;
protected:
    RefPtr<sf::Texture> m_texture;
};

#endif // SFMLTEXTURE_H
