#include "Window.h"

#include "Application.h"
#include "Backend.h"
#include "sfml/SFMLBackend.h"

OwnPtr<Window> Window::s_the_window;

void Window::update(float dt)
{
    ASSERT(m_backend.is_not_null());
    // m_backend->clear_states();
    m_backend->update(dt);
}

void Window::draw()
{
    Renderer::the().draw();
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

String Window::title()
{
    return m_backend->window_title();
}

void Window::set_title(const StringView& title)
{
    m_backend->set_window_title(title);
}

void Window::set_size(const glm::vec2& size)
{
    m_backend->set_window_size(size);
}

bool Window::is_mouse_down()
{
    NOTIMPL
    return false;
}

bool Window::is_key_pressed(Key key)
{
    ASSERT(m_backend.is_not_null());
    return m_backend->is_key_pressed(key);
}

Window& Window::the()
{
    if (!Window::s_the_window)
    {
        // FIXME: Always SFML
        Window::s_the_window = OwnPtr<Window>(new Window(BackendImplementation::SFML));
    }
    return *Window::s_the_window;
}

Window::Window(BackendImplementation type) : m_backend(/* what should we pass backend? */)
{
    switch (type)
    {
    case BackendImplementation::SFML:
        m_backend = OwnPtr<Backend>(new SFMLBackend());
        break;
    }
    ASSERT(m_backend);
}
