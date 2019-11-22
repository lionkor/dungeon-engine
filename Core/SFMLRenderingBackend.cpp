#include "SFMLRenderingBackend.h"

SFMLRenderingBackend::SFMLRenderingBackend()
    : m_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window"))
{
}

void SFMLRenderingBackend::clear()
{
    ASSERT(m_window);
    m_window->clear();
}

void SFMLRenderingBackend::draw_everything() { NOTIMPL }

void SFMLRenderingBackend::display()
{
    ASSERT(m_window);
    m_window->display();
}

void SFMLRenderingBackend::set_window_title(const StringView& title)
{
    ASSERT(m_window);
    m_window->setTitle(to_sf_string(title));
}

void SFMLRenderingBackend::set_window_size(const glm::vec2& size)
{
    ASSERT(m_window);
    m_window->setSize(
        sf::Vector2u { static_cast<uint>(size.x), static_cast<uint>(size.y) });
}

void SFMLRenderingBackend::register_rectangle(glm::vec2 top_left, glm::vec2 w_h)
{
    NOTIMPL
}

void SFMLRenderingBackend::register_triangle(glm::vec2 first, glm::vec2 second,
                                             glm::vec2 third)
{
    NOTIMPL
}
