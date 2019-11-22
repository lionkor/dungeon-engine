#ifndef WINDOW_H
#define WINDOW_H

#include "Global.h"
#include "Renderer.h"

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

protected:
    Window(BackendImplementation type, RawPtr<Application> app);

    OwnPtr<Renderer> m_renderer;
    OwnPtr<Backend> m_backend;
    RawPtr<Application> m_application;
};

#endif // WINDOW_H
