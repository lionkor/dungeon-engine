#include "File.h"
#include "../Rendering/Texture.h"

File::File(const Path& path)
    : std::fstream(path) {
}

File::~File() {
}
