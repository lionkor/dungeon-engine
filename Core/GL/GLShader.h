#ifndef GLSHADER_H
#define GLSHADER_H

#include "../Rendering/Shader.h"

class GLShader : public Shader
{
public:
    GLShader(StringView shader_name);

    virtual void load() override;
    virtual void compile() override;

protected:
    GLuint          m_program_id;
    bool            m_is_loaded;
    GenericResource m_vshader_source;
    GenericResource m_fshader_source;
};

#endif // GLSHADER_H
