#ifndef SFMLRENDERINGBACKEND_H
#define SFMLRENDERINGBACKEND_H

#include "../Global.h"
#include "../Backend.h"
#include "SFMLMaterial.h"
#include "SFMLBufferInterval.h"

class SFMLBackend : public Backend
{
public:
    SFMLBackend(Window& window);

    virtual void update(float) override;
    virtual void clear() override;
    virtual void draw() override;
    virtual void display() override;
    virtual void close_window() override;
    virtual void set_window_title(const StringView& title) override;
    virtual void set_window_size(const glm::vec2& size) override;

    virtual GUID register_polygon(const Polygon& polygon) override;
    virtual GUID register_rectangle(glm::vec2 top_left, glm::vec2 w_h,
                                    const RefPtr<Material>& material) override;
    virtual GUID register_triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third,
                                   const RefPtr<Material>& material) override;

protected:
    UnorderedMap<GUID, SFMLBufferInterval> m_buffer_intervals;
    OwnPtr<sf::RenderWindow> m_render_window;
    sf::VertexArray m_vertexarray;
    sf::Event event;
};

#endif // SFMLRENDERINGBACKEND_H
