#include "SFMLBackend.h"
#include "SFMLMaterial.h"
#include "SFMLTexture.h"
#include "../ECS/SpriteRenderComponent.h"
#include "../Window.h"

sf::String to_sf_string(const String& str)
{
    return sf::String(str.c_str());
}

sf::String to_sf_string(const StringView& str)
{
    return sf::String(str.c_str());
}

sf::Vector2f to_sf_vector2f(const vec2& v)
{
    return sf::Vector2f(v.x, v.y);
}

sf::Color to_sf_color(const Color& v)
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

    for (auto& varray : m_varrays)
    {
        m_render_window->draw(varray.first, sf::RenderStates(varray.second));
    }

    // FIXME: add frustrum culling :)

    for (auto& pair : m_sprites)
    {
        m_render_window->draw(pair.second.first);
    }
}

void SFMLBackend::display()
{
    ASSERT(m_render_window);
    m_render_window->display();
}

void SFMLBackend::close_window()
{
    m_render_window->close();
}

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
    auto texture =
        sprite.material.as<SFMLMaterial>().texture().as<SFMLTexture>().sf_texture();

    sf::Sprite sp(*texture);

    sp.setPosition(to_sf_vector2f(sprite.rectangle.position));

    float x_m = sprite.rectangle.size.x / sp.getGlobalBounds().width;
    float y_m = sprite.rectangle.size.y / sp.getGlobalBounds().height;

    sp.setScale({ x_m, y_m });

    m_sprites.insert_or_assign(sprite.guid(), std::pair(sp, texture));

    return sprite.guid();
}

GUID SFMLBackend::submit(const SpriteRenderComponent& sprite_render_comp)
{
    const Sprite& sprite = sprite_render_comp.sprite();
    const Entity& entity = sprite_render_comp.entity();

    auto texture =
        sprite.material.as<SFMLMaterial>().texture().as<SFMLTexture>().sf_texture();

    sf::Sprite sp(*texture);

    // SprRC positions are relative to the entity's position
    sp.setPosition(
        to_sf_vector2f(entity.transform().position() + sprite.rectangle.position));

    float x_m = sprite.rectangle.size.x / sp.getGlobalBounds().width;
    float y_m = sprite.rectangle.size.y / sp.getGlobalBounds().height;

    sp.setScale({ x_m, y_m });

    m_sprites.insert_or_assign(sprite.guid(), std::pair(sp, texture));

    return sprite_render_comp.guid();
}

GUID SFMLBackend::submit(const Polygon& polygon)
{
    sf::VertexArray varray(sf::PrimitiveType::Triangles);
    for (auto& triangle : polygon.triangles)
    {
        for (uchar i = 0; i < 3; ++i)
        {
            varray.append(sf::Vertex(to_sf_vector2f(triangle.points[i]),
                                     to_sf_color(polygon.material->color())));
        }
    }
    m_varrays.emplace_back(varray, polygon.material.as<SFMLMaterial>()
                                       .texture()
                                       .as<SFMLTexture>()
                                       .sf_texture()
                                       .get());
}
