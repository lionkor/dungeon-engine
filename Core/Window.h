#ifndef WINDOW_H
#define WINDOW_H

#include "Global.h"
#include "Rendering/Renderer.h"
#include "Keys.h"

class Application;

class Window
{
public:
    virtual void update(float dt);
    virtual void draw();

    Backend&       backend();
    const Backend& backend() const;

    String title();
    void   set_title(const StringView& title);
    void   set_size(const vec2& size);

    bool is_mouse_down();
    bool is_key_pressed(Key key);

    static Window& the();

protected:
    static OwnPtr<Window> s_the_window;

    Window(BackendImplementation type);

    OwnPtr<Backend> m_backend;
};

#endif // WINDOW_H
