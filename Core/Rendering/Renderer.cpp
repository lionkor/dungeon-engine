#include "Renderer.h"
#include "../sfml/SFMLBackend.h"
#include "../Window.h"
#include "../Application.h"

void Renderer::draw()
{
    m_window.backend().clear();
    m_window.backend().draw();
    m_window.backend().display();
}

RefPtr<Material> Renderer::create_material(const RefPtr<Texture>& tex, Color color)
{
    return m_window.backend().create_material(tex, color);
}

Renderer::Renderer(Window& window, Application& app)
    : m_window(window), m_application(app)
{
}
