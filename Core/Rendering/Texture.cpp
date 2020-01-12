#include "Texture.h"
#include "../IO/File.h"
#include "../Application.h"
#include "../sfml/SFMLTexture.h"
#include "../GL/GLTexture.h"

Texture::Texture() {
}

Texture* new_sfml_texture(const Path& path) {
    return new SFMLTexture(path);
}

Texture* new_sfml_texture(const GenericResource& res) {
    return new SFMLTexture(res);
}

Texture* new_gl_texture(const Path& path) {
    return new GLTexture(path);
}

Texture* new_gl_texture(const GenericResource& res) {
    return new GLTexture(res);
}

Texture::~Texture() {
}
