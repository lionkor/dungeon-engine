#ifndef RENDERER_H
#define RENDERER_H

#include "Global.h"
#include "Backend.h"

class Window;
class Application;

class Renderer
{
    OBJECT(Renderer)
public:
    
    virtual void draw();

protected:
    Renderer(RawPtr<Window> window, RawPtr<Application> app);
    
    RawPtr<Window> m_window;
    RawPtr<Application> m_application;
};

#endif // RENDERER_H
