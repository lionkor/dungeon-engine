#include "Window.h"
#include "Backend.h"
#include "sfml/SFMLBackend.h"

void Window::draw() { m_renderer->draw(); }

Backend& Window::backend()
{
    ASSERT(m_backend);
    return *m_backend;
}

const Backend& Window::backend() const
{
    ASSERT(m_backend);
    return *m_backend;
}

void Window::set_title(const StringView& title) { m_backend->set_window_title(title); }

void Window::set_size(const glm::vec2& size) { m_backend->set_window_size(size); }

Renderer& Window::renderer() { return *m_renderer; }

const Renderer& Window::renderer() const { return *m_renderer; }

Window::Window(BackendImplementation type, Application& app)
    : m_renderer(Renderer::construct(*this, app)), m_backend(nullptr), m_application(app)
{
    switch (type)
    {
        case BackendImplementation::SFML:
            m_backend = OwnPtr<Backend>(new SFMLBackend(*this));
            break;
    }
    ASSERT(m_backend);
}
