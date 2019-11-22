#ifndef SFMLRENDERINGBACKEND_H
#define SFMLRENDERINGBACKEND_H

#include "../Global.h"
#include "../RenderingBackend.h"
#include "SFMLMaterial.h"

class SFMLRenderingBackend : public Backend
{
public:
    SFMLRenderingBackend();

    virtual void clear() override;
    virtual void draw() override;
    virtual void display() override;
    virtual void set_window_title(const StringView& title) override;
    virtual void set_window_size(const glm::vec2& size) override;
    virtual void register_rectangle(glm::vec2 top_left, glm::vec2 w_h,
                                    const RefPtr<Material>& material) override;
    virtual void register_triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third,
                                   const RefPtr<Material>& material) override;

protected:
    OwnPtr<sf::RenderWindow> m_window;
};

#endif // SFMLRENDERINGBACKEND_H
