#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "Window.h"
#include "State.h"
#include "ECS/Entity.h"

class Application
{
public:
    // FIXME: add a reason / error code?
    void shutdown();
    void run();
    
    State& state();
    const State& state() const;
    
    static Application& the();
    
protected:
    Application();

    static OwnPtr<Application> s_the_application;
    
    OwnPtr<State> m_current_state;
    bool m_is_running;
};

#endif // APPLICATION_H
