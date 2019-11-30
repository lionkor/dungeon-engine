#ifndef RENDERER_H
#define RENDERER_H

#include "../Global.h"
#include "../Backend.h"

class Renderer
{
public:
    static Renderer& the();
    
    virtual void draw();
    
    virtual GUID submit(const Sprite& spr);
    
protected:
    Renderer();
    
    static OwnPtr<Renderer> s_the_renderer;
};

#endif // RENDERER_H
