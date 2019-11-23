#ifndef RENDERER_H
#define RENDERER_H

#include "../Global.h"
#include "../Backend.h"

class Window;
class Application;

class Renderer
{
    OBJECT(Renderer)
public:
    
    virtual void draw();

protected:
    Renderer(Window& window, Application& app);
    
    Window& m_window;
    Application& m_application;
};

#endif // RENDERER_H
