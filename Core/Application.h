#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "Window.h"
#include "State.h"
#include "ECS/Entity.h"

class Application
{
    OBJECT(Application);

public:
    Window& window();
    const Window& window() const;

    inline Renderer& renderer();
    inline const Renderer& renderer() const;
    
    // FIXME: add a reason / error code?
    void shutdown();
    void run();
    
    State& state();
    const State& state() const;
    
    
    static Application& the() { return *Application::s_the_application; }
    
protected:
    Application(BackendImplementation type);

    static OwnPtr<Application> s_the_application;
    
    OwnPtr<Window> m_window;
    OwnPtr<State> m_current_state;
    bool m_is_running;
};

#endif // APPLICATION_H
