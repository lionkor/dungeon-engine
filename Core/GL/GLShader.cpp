#include "GLShader.h"

GLShader::GLShader(StringView shader_name)
    : m_vshader_source(Path(String::format("res/shaders/", shader_name, ".vertex"))),
      m_fshader_source(Path(String::format("res/shaders/", shader_name, ".fragment")))
{
}

void GLShader::load()
{
    m_vshader_source.load();
    m_fshader_source.load();
    m_is_loaded = true;
}

#define KB 1024

static GLuint compile_single(const char* src, GLuint type)
{
    ASSERT(type == GL_FRAGMENT_SHADER || type == GL_VERTEX_SHADER);
    GLuint id = glCreateShader(type);
    GLint  rc = GL_FALSE;
    int    info_log_len;
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &rc);
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_len);
    if (info_log_len > 0)
    {
        ASSERT(info_log_len < 2 * KB);
        char log[2 * KB];
        glGetShaderInfoLog(id, info_log_len, nullptr, log);
        ERROR(log);
    }
    return id;
}

void GLShader::compile()
{
    ASSERT(m_is_loaded);
    char* vs_src = m_vshader_source.data_as_void_ptr().as_ptr<char>();
    char* fs_src = m_fshader_source.data_as_void_ptr().as_ptr<char>();

    GLuint vs_id = compile_single(vs_src, GL_VERTEX_SHADER);
    GLuint fs_id = compile_single(fs_src, GL_FRAGMENT_SHADER);

    m_program_id = glCreateProgram();
    glAttachShader(m_program_id, vs_id);
    glAttachShader(m_program_id, fs_id);
    glLinkProgram(m_program_id);

    GLint rc = GL_FALSE;
    int   info_log_len;
    glGetProgramiv(m_program_id, GL_LINK_STATUS, &rc);
    glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &info_log_len);
    if (info_log_len > 0)
    {
        ASSERT(info_log_len < 2 * KB);
        char log[2 * KB];
        glGetProgramInfoLog(m_program_id, info_log_len, nullptr, log);
        ERROR(log);
    }

    glDetachShader(m_program_id, vs_id);
    glDetachShader(m_program_id, fs_id);

    glDeleteShader(vs_id);
    glDeleteShader(fs_id);

    m_vshader_source.unload();
    m_fshader_source.unload();
}
