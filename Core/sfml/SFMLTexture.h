#ifndef SFMLTEXTURE_H
#define SFMLTEXTURE_H

#include "../Global.h"
#include "../Texture.h"

class SFMLTexture : public Texture
{
public:
    SFMLTexture();
    
    virtual OwnPtr<Texture> load_from_file(const Path& path) override;
    virtual OwnPtr<Texture> load_from_memory(const GenericResource& res) override;
};

#endif // SFMLTEXTURE_H
