#ifndef RENDERINGBACKEND_H
#define RENDERINGBACKEND_H

#include "Global.h"

class Material;
class Texture;

class Backend
{
public:
    Backend() {}
    virtual ~Backend() {}

    virtual void clear() = 0;
    virtual void draw() = 0;
    virtual void display() = 0;
    virtual void set_window_title(const StringView& title) = 0;
    virtual void set_window_size(const vec2& size) = 0;

    std::function<void()> close_event_handler;

    virtual void register_rectangle(vec2 top_left, vec2 w_h, const RefPtr<Material>& material) = 0;
    virtual void register_triangle(vec2 first, vec2 second, vec2 third, const RefPtr<Material>& material) = 0;
    // virtual void register_circle(vec2 pos, vec2 size, const RefPtr<Material>& material) = 0;
private:
};

#endif // RENDERINGBACKEND_H
