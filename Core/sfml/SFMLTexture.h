#ifndef SFMLTEXTURE_H
#define SFMLTEXTURE_H

#include "../Global.h"
#include "../Rendering/Texture.h"

class SFMLTexture : public Texture
{
public:
    SFMLTexture();
    
    virtual void load_from_file(const Path& path) override;
    virtual void load_from_memory(const GenericResource& res) override;
    
    RefPtr<sf::Texture> sf_texture() { return m_texture; }
protected:
    RefPtr<sf::Texture> m_texture;
};

#endif // SFMLTEXTURE_H
