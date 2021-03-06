#ifndef SFMLRENDERINGBACKEND_H
#define SFMLRENDERINGBACKEND_H

#include "../Global.h"
#include "../Backend.h"
#include "../Rendering/Material.h"
#include "SFMLBufferInterval.h"
#include <SFML/Graphics/VertexArray.hpp>

extern sf::String   to_sf_string(const String& str);
extern sf::String   to_sf_string(const StringView& str);
extern sf::Vector2f to_sf_vector2f(const vec2& v);
extern sf::Color    to_sf_color(const Color& v);

struct SFMLSpriteRenderInfo
{
    const Transform*    transform;
    vec2                relative_pos;
    sf::Sprite          sprite;
    RefPtr<sf::Texture> texture;
};

class SFMLBackend : public Backend
{
public:
    SFMLBackend();
    ~SFMLBackend();

    virtual void   update(float) override;
    virtual void   clear() override;
    virtual void   draw() override;
    virtual void   display() override;
    virtual void   close_window() override;
    virtual String window_title() const;
    virtual void   set_window_title(const StringView& title) override;
    virtual void   set_window_size(const glm::vec2& size) override;

    virtual GUID submit(const Sprite& sprite) override;
    virtual GUID submit(const SpriteRenderComponent& sprite_render_comp) override;
    virtual GUID submit(const Polygon& polygon) override;

protected:
    UnorderedMap<GUID, SFMLSpriteRenderInfo>         m_sprites;
    Vector<std::pair<sf::VertexArray, sf::Texture*>> m_varrays;
    UnorderedMap<GUID, SFMLBufferInterval>           m_buffer_intervals;
    OwnPtr<sf::RenderWindow>                         m_render_window;
    sf::VertexArray                                  m_vertexarray;
    sf::Event                                        event;
};

#endif // SFMLRENDERINGBACKEND_H
