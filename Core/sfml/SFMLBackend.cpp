#include "SFMLBackend.h"

SFMLBackend::SFMLBackend()
    : m_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window"))
{
}

void SFMLBackend::clear()
{
    ASSERT(m_window);
    m_window->clear();
}

void SFMLBackend::draw() 
{ 
    NOTIMPL 
}

void SFMLBackend::display()
{
    ASSERT(m_window);
    m_window->display();
}

void SFMLBackend::set_window_title(const StringView& title)
{
    ASSERT(m_window);
    m_window->setTitle(to_sf_string(title));
}

void SFMLBackend::set_window_size(const glm::vec2& size)
{
    ASSERT(m_window);
    m_window->setSize(
                sf::Vector2u { static_cast<uint>(size.x), static_cast<uint>(size.y) });
}

void SFMLBackend::register_rectangle(glm::vec2 top_left, glm::vec2 w_h, const RefPtr<Material>& material)
{
    NOTIMPL
}

void SFMLBackend::register_triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third, const RefPtr<Material>& material)
{
    NOTIMPL
}

