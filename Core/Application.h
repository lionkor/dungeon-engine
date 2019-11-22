#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "Window.h"

class Application
{
    OBJECT(Application);

public:
    void set_window_title(const StringView& title);
    void set_window_size(vec2 size);

protected:
    Application(BackendImplementation type);

    OwnPtr<Window> m_window;
    bool m_is_running;
};

#endif // APPLICATION_H
