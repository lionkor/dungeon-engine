#ifndef RENDERINGBACKEND_H
#define RENDERINGBACKEND_H

#include "Global.h"
#include "Keys.h"
#include "Rendering/Primitives.h"
#include "Rendering/Sprite.h"

class Material;
class Texture;
class Window;

class Backend
{
public:
    Backend() {}
    virtual ~Backend() {}

    virtual void update(float)                             = 0;
    virtual void clear()                                   = 0;
    virtual void draw()                                    = 0;
    virtual void display()                                 = 0;
    virtual void close_window()                            = 0;
    virtual void set_window_title(const StringView& title) = 0;
    virtual void set_window_size(const vec2& size)         = 0;

    virtual GUID submit(const Sprite& sprite)   = 0;
    virtual GUID submit(const Polygon& polygon) = 0;

    inline virtual bool is_key_pressed(Key key) const final
    {
        return m_pressed_keys.find(key) != m_pressed_keys.end();
    }

protected:
    UnorderedSet<Key> m_pressed_keys;
};

#endif // RENDERINGBACKEND_H
