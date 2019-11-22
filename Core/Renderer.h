#ifndef RENDERER_H
#define RENDERER_H

#include "Global.h"
#include "RenderingBackend.h"

enum class BackendImplementation
{
    SFML,
};

class Renderer
{
    OBJECT(Renderer)
public:
    RenderingBackend& rendering_backend();
    
    virtual void draw();

protected:
    Renderer(BackendImplementation type);

    OwnPtr<RenderingBackend> m_backend;
};

#endif // RENDERER_H
