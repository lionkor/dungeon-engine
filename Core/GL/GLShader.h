#ifndef GLSHADER_H
#define GLSHADER_H

#include "../Rendering/Shader.h"

class GLShader : public Shader
{
public:
    GLShader(const Path& path);
    
    void load();
    void compile();
    
    GLuint program_id;
};

#endif // GLSHADER_H
