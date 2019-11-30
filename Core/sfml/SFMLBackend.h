#ifndef SFMLRENDERINGBACKEND_H
#define SFMLRENDERINGBACKEND_H

#include "../Global.h"
#include "../Backend.h"
#include "SFMLBufferInterval.h"

class SFMLBackend : public Backend
{
public:
    SFMLBackend();

    virtual void update(float) override;
    virtual void clear() override;
    virtual void draw() override;
    virtual void display() override;
    virtual void close_window() override;
    virtual void set_window_title(const StringView& title) override;
    virtual void set_window_size(const glm::vec2& size) override;

    virtual GUID submit(const Sprite& sprite) override;
    virtual GUID submit(const Polygon& polygon) override;

protected:
    UnorderedMap<GUID, SFMLBufferInterval> m_buffer_intervals;
    Vector<sf::Sprite> m_sprites;
    OwnPtr<sf::RenderWindow> m_render_window;
    sf::VertexArray m_vertexarray;
    sf::Event event;
};

#endif // SFMLRENDERINGBACKEND_H
