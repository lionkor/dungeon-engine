#include "Shader.h"
#include "../GL/GLShader.h"

Shader::Shader()
{
}

Shader* new_gl_shader(StringView shader_name)
{
    return new GLShader(shader_name);
}

Shader::~Shader()
{
}
