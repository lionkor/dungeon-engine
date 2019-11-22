#ifndef RENDERINGBACKEND_H
#define RENDERINGBACKEND_H

#include "Global.h"

class RenderingBackend
{
public:
    RenderingBackend() {}
    virtual ~RenderingBackend() {}
    
    virtual void clear() = 0;
    virtual void display() = 0;
    
    virtual void register_rectangle(vec2 top_left, vec2 w_h) = 0;
    virtual void register_triangle(vec2 first, vec2 second, vec2 third) = 0;
    // virtual void register_circle(vec2 pos, vec2 size) = 0;
private:
};

#endif // RENDERINGBACKEND_H
