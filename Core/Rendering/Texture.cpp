#include "Texture.h"
#include "../IO/File.h"
#include "../Application.h"
#include "../sfml/SFMLTexture.h"

Texture::Texture()
{
}

Texture* new_sfml_texture(const Path& path)
{
    return new SFMLTexture(path);
}

Texture* new_sfml_texture(const GenericResource& res)
{
    return new SFMLTexture(res);
}

Texture::~Texture()
{
}
