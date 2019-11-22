#ifndef WINDOW_H
#define WINDOW_H

#include "Global.h"
#include "Renderer.h"

class Window
{
    OBJECT(Window);
public:
    
    virtual void draw();
    
protected:
    Window(BackendImplementation type);
    
    OwnPtr<Renderer> m_renderer;
};

#endif // WINDOW_H
