#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Global.h"
#include "Component.h"

class Transform final : public Component
{
public:
    Transform(Entity& entity, const vec2& position, float rotation = 0.0f);

    vec2& position();
    const vec2& position() const;

    void set_position(const vec2& pos);
    void set_rotation(float rot);

    float& rotation();
    const float& rotation() const;
    
    virtual void update(float) override {}

protected:
    vec2 m_position;
    float m_rotation;
    
};

#endif // TRANSFORM_H
