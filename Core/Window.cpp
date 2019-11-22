#include "Window.h"


void Window::draw()
{
    m_renderer->draw();
}

Window::Window(BackendType type)
    : m_renderer(Renderer::construct(type))
{
}

