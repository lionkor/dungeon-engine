#ifndef GLBACKEND_H
#define GLBACKEND_H

#include "../Backend.h"
#include "../Global.h"

namespace GL
{
void gl_error_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                       GLsizei length, const GLchar* message, const void* userParam);
void error_callback(int error, const char* description);
} // namespace GL

class GLBackend : public Backend
{
public:
    GLBackend();
    ~GLBackend();

    virtual void   update(float) override;
    virtual void   clear() override;
    virtual void   draw() override;
    virtual void   display() override;
    virtual void   close_window() override;
    virtual String window_title() const override;
    virtual void   set_window_title(const StringView& title) override;
    virtual void   set_window_size(const glm::vec2& size) override;
    virtual vec2   window_size() const override;
    virtual GUID   submit(const Sprite& sprite) override;
    virtual GUID   submit(const SpriteRenderComponent& sprite_render_comp) override;
    virtual GUID   submit(const Polygon& polygon) override;
    virtual bool   is_key_pressed(Key key) const override;

private:
    GLFWwindow* m_window;
};

#endif // GLBACKEND_H
