#include "Application.h"

Application::Application(BackendImplementation type)
    : m_window(Window::construct(type)), m_is_running(true)
{
    while (m_is_running)
    {
        m_window->draw();
    }
}
