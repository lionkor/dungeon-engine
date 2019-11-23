#ifndef WINDOW_H
#define WINDOW_H

#include "Global.h"
#include "Rendering/Renderer.h"

enum class BackendImplementation
{
    SFML,
};

class Application;

class Window
{
    OBJECT(Window);

public:
    virtual void draw();
    Backend& backend();
    const Backend& backend() const;

    void set_title(const StringView& title);
    void set_size(const vec2& size);

    Renderer& renderer();
    const Renderer& renderer() const;

protected:
    Window(BackendImplementation type, Application& app);

    OwnPtr<Renderer> m_renderer;
    OwnPtr<Backend> m_backend;
    Application& m_application;
};

#endif // WINDOW_H
