#ifndef RENDERINGBACKEND_H
#define RENDERINGBACKEND_H

#include "Global.h"

class Material;
class Texture;
class Window;

class Backend
{
public:
    Backend(RawPtr<Window> window) : m_window(window) {}
    virtual ~Backend() {}

    virtual void clear() = 0;
    virtual void draw() = 0;
    virtual void display() = 0;
    virtual void set_window_title(const StringView& title) = 0;
    virtual void set_window_size(const vec2& size) = 0;

    virtual void register_rectangle(vec2 top_left, vec2 w_h,
                                    const RefPtr<Material>& material) = 0;
    virtual void register_triangle(vec2 first, vec2 second, vec2 third,
                                   const RefPtr<Material>& material) = 0;

protected:
    RawPtr<Window> m_window;
};

#endif // RENDERINGBACKEND_H
