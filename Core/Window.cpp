#include "Window.h"
#include "Backend.h"
#include "Application.h"
#include "sfml/SFMLBackend.h"

void Window::update(float dt)
{
    ASSERT(m_backend.is_not_null());
    m_backend->clear_states();
    m_backend->update(dt);
}

void Window::draw() 
{ 
    m_renderer->draw(); 
}

Backend& Window::backend()
{
    ASSERT(m_backend.is_not_null());
    return *m_backend;
}

const Backend& Window::backend() const
{
    ASSERT(m_backend.is_not_null());
    return *m_backend;
}

void Window::set_title(const StringView& title) { m_backend->set_window_title(title); }

void Window::set_size(const glm::vec2& size) { m_backend->set_window_size(size); }

void Window::close()
{
    m_application.shutdown();
}

Renderer& Window::renderer() { return *m_renderer; }

const Renderer& Window::renderer() const { return *m_renderer; }

bool Window::is_mouse_down()
{
    NOTIMPL
}

bool Window::is_key_pressed(Key key)
{
    ASSERT(m_backend.is_not_null());
    return m_backend->is_key_pressed(key);
}

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
