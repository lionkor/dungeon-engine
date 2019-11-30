#include "SFMLBackend.h"
#include "../Window.h"

static inline sf::String to_sf_string(const String& str)
{
    return sf::String(str.c_str());
}

static inline sf::String to_sf_string(const StringView& str)
{
    return sf::String(str.c_str());
}

static inline sf::Vector2f to_sf_vector2f(const vec2& v)
{
    return sf::Vector2f(v.x, v.y);
}

static inline sf::Color to_sf_color(const Color& v)
{
    return sf::Color(v.r, v.g, v.b, v.a);
}

SFMLBackend::SFMLBackend()
    : m_render_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window")),
      m_vertexarray(sf::PrimitiveType::Triangles)
{
}

void SFMLBackend::update(float dt)
{
    // verbose(__PRETTY_FUNCTION__ << " with dt = " << dt);

    while (m_render_window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                verbose(__FUNCTION__ << "Closed");
                Window::the().close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    verbose(__FUNCTION__ << "KeyPressed");
                    case sf::Keyboard::B:
                        m_pressed_keys.insert(Key::B);
                        break;
                    default:
                        NOTIMPL
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                verbose(__FUNCTION__ << "KeyRelease");
                switch (event.key.code)
                {
                    case sf::Keyboard::B:
                        m_pressed_keys.erase(Key::B);
                        break;
                    case sf::Keyboard::Escape:
                        Window::the().close();
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

void SFMLBackend::draw()
{
    ASSERT(m_render_window);
    m_render_window->draw(m_vertexarray);
    for (const auto& spr : m_sprites)
    {
        m_render_window->draw(spr);
    }
}

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

GUID SFMLBackend::submit(const Sprite& sprite)
{
    sf::Sprite spr;
    sf::Texture tex;
    tex.loadFromMemory(sprite.material.texture().pixels(),
                       sprite.material.texture().width() *
                           sprite.material.texture().height());
    spr.setTexture(tex);
    spr.setColor(to_sf_color(sprite.material.color()));
    spr.setTextureRect(sf::IntRect(sprite.rectangle.position.x,
                                   sprite.rectangle.position.y, sprite.rectangle.size.x,
                                   sprite.rectangle.size.y));
    
    m_sprites.push_back(spr);
    
    // FIXME: This is shit.
    return GUID();
    /*
    Vector<Triangle> ts(2);
    ts[0] = Triangle { sprite.rectangle.position,
                       vec2 { sprite.rectangle.position.x + sprite.rectangle.size.x,
                              sprite.rectangle.position.y },
                       vec2 { sprite.rectangle.position.x,
                              sprite.rectangle.position.y + sprite.rectangle.size.y } };
    ts[1] = Triangle { sprite.rectangle.position + sprite.rectangle.size,
                       vec2 { sprite.rectangle.position.x + sprite.rectangle.size.x,
                              sprite.rectangle.position.y },
                       vec2 { sprite.rectangle.position.x,
                              sprite.rectangle.position.y + sprite.rectangle.size.y } };
    return submit(Polygon { ts, sprite.material });
    */
}

GUID SFMLBackend::submit(const Polygon& polygon)
{
    SizeT start = m_vertexarray.getVertexCount();
    SFMLBufferInterval interval(start, polygon.triangles.size() * 3, polygon.material);
    for (const auto& triangle : polygon.triangles)
    {
        for (uchar i = 0; i < 3; ++i)
        {
            m_vertexarray.append(sf::Vertex(to_sf_vector2f(triangle.points[i]),
                                            to_sf_color(polygon.material.color())));
        }
    }
    m_buffer_intervals.emplace(std::pair(interval.guid(), interval));
    return interval.guid();
}
