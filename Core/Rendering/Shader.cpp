#include "Shader.h"
#include "../GL/GLShader.h"

Shader::Shader()
{
}

Shader* new_gl_shader(const Path& path)
{
    return new GLShader(path);
}

Shader::~Shader()
{
}
