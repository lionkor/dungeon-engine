#include "SFMLBackend.h"
#include "../Window.h"

SFMLBackend::SFMLBackend(Window& window)
    : Backend(window),
      m_render_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window")),
      m_vertexarray(sf::PrimitiveType::Triangles)
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

GUID SFMLBackend::register_polygon(const Polygon& polygon)
{
    SizeT start = m_vertexarray.getVertexCount();
    SFMLBufferInterval interval;
    interval.index = start;
    interval.count = polygon.triangles.size() * 3;
    interval.material = reinterpret_cast<SFMLMaterial&>(*polygon.material);
    m_vertexarray.resize(start + polygon.triangles.size() * 3);
    SizeT tri = 0;
    for (const auto& triangle : polygon.triangles)
    {
        for (uchar i = 0; i < 3; ++i)
        {
            m_vertexarray[start + i * tri].position = to_sf_vector2f(triangle.points[i]);
            m_vertexarray[start + i * tri].color =
                reinterpret_cast<SFMLMaterial&>(*polygon.material).sf_color();
        }
        ++tri;
    }
    m_buffer_intervals.emplace(std::pair(interval.guid(), interval));
    return interval.guid();
}

GUID SFMLBackend::register_rectangle(glm::vec2 top_left, glm::vec2 w_h,
                                     const RefPtr<Material>& material) { NOTIMPL }

GUID SFMLBackend::register_triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third,
                                    const RefPtr<Material>& material)
{
    NOTIMPL
}
