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

protected:
    Application(BackendImplementation type);

    OwnPtr<Window> m_window;
    OwnPtr<State> m_current_state;
    bool m_is_running;
};

#endif // APPLICATION_H
