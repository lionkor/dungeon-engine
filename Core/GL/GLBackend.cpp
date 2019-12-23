#include "GLBackend.h"
#include "../Window.h"
#include <GLFW/glfw3.h>

void GL::gl_error_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                           GLsizei length, const GLchar* message, const void* userParam)
{
    LOG("GL DEBUG MESSAGE: source=" << source << " type=" << type << " id=" << id
                                    << " severity=" << severity << " message=\""
                                    << message << "\"");
}

void GL::error_callback(int error, const char* description)
{
    LOG("ERROR CALLBACK: error=" << error << " description=\"" << description << "\"");
}

GLBackend::GLBackend()
{
    glfwSetErrorCallback(GL::error_callback);
    int glfw_rc = glfwInit();
    ASSERT(glfw_rc == GLFW_TRUE);

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // FIXME: pass width / height from settings or something
    m_window = glfwCreateWindow(640, 480, "Window", nullptr, nullptr);
    ASSERT(m_window);

    glfwMakeContextCurrent(m_window);
    glewExperimental = true;
    GLenum glew_rc   = glewInit();
    ASSERT(glew_rc == GLEW_OK);

    glDebugMessageCallback(GL::gl_error_callback, nullptr);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    LOG("glfw version: " << glfwGetVersionString());
    LOG("glew version: " << glewGetString(GLEW_VERSION));
    LOG("GL version: " << glGetString(GL_VERSION));
    LOG("GL vendor: " << glGetString(GL_VENDOR));
    LOG("GL renderer: " << glGetString(GL_RENDERER));
    LOG("GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION));
}

GLBackend::~GLBackend()
{
    glfwTerminate();
    verbose("GLBackend dtor called, glfw terminated");
}

bool GLBackend::is_key_pressed(Key key) const
{
    return glfwGetKey(m_window, glfw_key_from_key(key)) == GLFW_PRESS;
}

void GLBackend::update(float)
{
    glfwPollEvents();
    // FIXME: Maybe we should check this from somewhere else?
    if (glfwWindowShouldClose(m_window))
        Application::the().shutdown(ShutdownHint::WindowClosed);
}

void GLBackend::clear()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLBackend::draw()
{
}

void GLBackend::display()
{
    glfwSwapBuffers(m_window);
}

void GLBackend::close_window()
{
    // already handled by dtor, through glfwTerminate!
}

String GLBackend::window_title() const
{
    // AFAIK, this doesn't exist in glfw
    NOTIMPL
}

void GLBackend::set_window_title(const StringView& title)
{
    glfwSetWindowTitle(m_window, title.c_str());
}

void GLBackend::set_window_size(const glm::vec2& size) { NOTIMPL }

glm::vec2 GLBackend::window_size() const
{
    int x;
    int y;
    glfwGetWindowSize(m_window, &x, &y);
    return vec2(x, y);
}

GUID GLBackend::submit(const Sprite& sprite) { NOTIMPL }

GUID GLBackend::submit(const SpriteRenderComponent& sprite_render_comp)
{
    return GUID();
}

GUID GLBackend::submit(const Polygon& polygon)
{
    NOTIMPL
}
