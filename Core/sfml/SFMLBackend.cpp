#include "SFMLBackend.h"
#include "SFMLMaterial.h"
#include "../Rendering/Material.h"
#include "SFMLTexture.h"
#include "../ECS/SpriteRenderComponent.h"
#include "../Window.h"
#include <SFML/Graphics/PrimitiveType.hpp>

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
    m_render_window->setFramerateLimit(-1);
}

SFMLBackend::~SFMLBackend()
{
}

void SFMLBackend::update(float)
{
    // verbose(__PRETTY_FUNCTION__ << " with dt = " << dt);

    while (m_render_window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            verbose(__FUNCTION__ << "Closed");
            Application::the().shutdown(ShutdownHint::WindowClosed);
            break;
        case sf::Event::KeyPressed:
            // FIXME: this is dirty :I
            verbose(__FUNCTION__ << "KeyPressed");
            set_key_pressed(static_cast<Key>(event.key.code));
            break;
        case sf::Event::KeyReleased:
            verbose(__FUNCTION__ << "KeyReleased");
            set_key_released(static_cast<Key>(event.key.code));
            break;
        case sf::Event::MouseMoved:
            // don't do anything
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
        ASSERT(pair.second.texture.is_not_null());
        pair.second.sprite.setPosition(
            to_sf_vector2f(pair.second.transform->position() + pair.second.relative_pos));

        m_render_window->draw(pair.second.sprite);
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

String SFMLBackend::window_title() const
{
    ASSERT(false);
    /* FIXME this does not exist for SFML */
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

glm::vec2 SFMLBackend::window_size() const { NOTIMPL }

GUID SFMLBackend::submit(const Sprite& sprite)
{
    ASSERT(false);
    auto texture =
        sprite.material.as<SFMLMaterial>().texture().as<SFMLTexture>().sf_texture();

    sf::Sprite sp(*texture);

    sp.setPosition(to_sf_vector2f(sprite.rectangle.position));

    float x_m = sprite.rectangle.size.x / sp.getGlobalBounds().width;
    float y_m = sprite.rectangle.size.y / sp.getGlobalBounds().height;

    sp.setScale({ x_m, y_m });


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

    SFMLSpriteRenderInfo info { &entity.transform(), sprite.rectangle.position, sp,
                                texture.get() };

    m_sprites.insert_or_assign(sprite.guid(), info);
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
