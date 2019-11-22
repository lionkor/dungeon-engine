#ifndef RENDERER_H
#define RENDERER_H

#include "Global.h"
#include "Backend.h"

enum class BackendImplementation
{
    SFML,
};

class Renderer
{
    OBJECT(Renderer)
public:
    Backend& rendering_backend();
    
    virtual void draw();

protected:
    Renderer(BackendImplementation type);

    OwnPtr<Backend> m_backend;
};

#endif // RENDERER_H
