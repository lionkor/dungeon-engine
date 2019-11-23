#include "SFMLBackend.h"
#include "../Window.h"

SFMLBackend::SFMLBackend(Window& window)
    : Backend(window),
      m_render_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window"))
{
}

void SFMLBackend::update(float)
{
    while (m_render_window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::B:
                        m_pressed_keys.insert(Key::B);
                        break;
                    default:
                        NOTIMPL
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::B:
                        m_pressed_keys.erase(Key::B);
                        break;
                    default:
                        NOTIMPL
                        break;
                }
                break;
            default:
                NOTIMPL
                break;
        }
    }
}

void SFMLBackend::clear()
{
    ASSERT(m_render_window);
    m_render_window->clear();
}

void SFMLBackend::draw() { NOTIMPL }

void SFMLBackend::display()
{
    ASSERT(m_render_window);
    m_render_window->display();
}

void SFMLBackend::close_window() { m_render_window->close(); }

void SFMLBackend::set_window_title(const StringView& title)
{
    ASSERT(m_render_window);
    m_render_window->setTitle(to_sf_string(title));
}

void SFMLBackend::set_window_size(const glm::vec2& size)
{
    ASSERT(m_render_window);
    m_render_window->setSize(
        sf::Vector2u { static_cast<uint>(size.x), static_cast<uint>(size.y) });
}

void SFMLBackend::register_rectangle(glm::vec2 top_left, glm::vec2 w_h,
                                     const RefPtr<Material>& material)
{
    NOTIMPL
}

void SFMLBackend::register_triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third,
                                    const RefPtr<Material>& material)
{
    NOTIMPL
}
