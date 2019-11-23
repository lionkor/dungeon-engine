#include "Window.h"
#include "Backend.h"
#include "sfml/SFMLBackend.h"

void Window::draw() { m_renderer->draw(); }

Backend& Window::backend()
{
    ASSERT(m_backend);
    return *m_backend;
}

Window::Window(BackendImplementation type, RawPtr<Application> app)
    : m_renderer(Renderer::construct(this, app)), m_backend(nullptr), m_application(app)
{
    switch (type)
    {
        case BackendImplementation::SFML:
            m_backend = OwnPtr<Backend>(new SFMLBackend(this));
            break;
    }
    ASSERT(m_backend);
}
