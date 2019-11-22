#include "Renderer.h"
#include "sfml/SFMLBackend.h"
#include "Window.h"
#include "Application.h"

void Renderer::draw()
{
    m_window->backend().clear();
    m_window->backend().draw();
    m_window->backend().display();
}

Renderer::Renderer(RawPtr<Window> window, RawPtr<Application> app)
    : m_window(window), m_application(app)
{
}
