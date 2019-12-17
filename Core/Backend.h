#ifndef RENDERINGBACKEND_H
#define RENDERINGBACKEND_H

#include "Global.h"
#include "Keys.h"
#include "Rendering/Primitives.h"
#include "Rendering/Sprite.h"
#include "ECS/SpriteRenderComponent.h"

class Material;
class Texture;
class Window;

class Backend
{
public:
    Backend() {}
    virtual ~Backend() {}

    virtual void   update(float)                             = 0;
    virtual void   clear()                                   = 0;
    virtual void   draw()                                    = 0;
    virtual void   display()                                 = 0;
    virtual void   close_window()                            = 0;
    virtual String window_title() const                      = 0;
    virtual void   set_window_title(const StringView& title) = 0;
    virtual void   set_window_size(const vec2& size)         = 0;

    virtual GUID submit(const Sprite& sprite)                            = 0;
    virtual GUID submit(const SpriteRenderComponent& sprite_render_comp) = 0;
    virtual GUID submit(const Polygon& polygon)                          = 0;

    inline virtual bool is_key_pressed(Key key) const final
    {
        return m_pressed_keys.find(key) != m_pressed_keys.end();
    }

    inline virtual void set_key_pressed(Key key) final { m_pressed_keys.emplace(key); }

    inline virtual void set_key_released(Key key) final { m_pressed_keys.erase(key); }

protected:
    UnorderedSet<Key> m_pressed_keys;
};

#endif // RENDERINGBACKEND_H
