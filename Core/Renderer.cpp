#include "Renderer.h"
#include "sfml/SFMLRenderingBackend.h"

Renderer::Renderer(BackendImplementation type)
{
    switch (type)
    {
        case BackendImplementation::SFML:
            m_backend = OwnPtr<Backend>(new SFMLRenderingBackend);
            break;
    }
    ASSERT(m_backend);
}

Backend& Renderer::rendering_backend()
{
    ASSERT(m_backend);
    return *m_backend;
}

void Renderer::draw()
{
    ASSERT(m_backend);
    
    m_backend->clear();
    m_backend->draw();
    m_backend->display();
}
