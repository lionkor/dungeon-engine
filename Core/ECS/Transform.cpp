#include "Transform.h"

Transform::Transform(Entity& entity, const glm::vec2& position, float rotation)
    : Component(entity), m_position(position), m_rotation(rotation)
{
}

glm::vec2& Transform::position()
{
    return m_position;
}

const glm::vec2& Transform::position() const
{
    return m_position;
}

void Transform::set_position(const glm::vec2& pos)
{
    m_position = pos;
}

void Transform::set_rotation(float rot)
{
    // FIXME: clamp rotation?
    m_rotation = rot;
}

void Transform::move_by(const vec2& offset)
{
    m_position += offset;
}

float& Transform::rotation()
{
    return m_rotation;
}

const float& Transform::rotation() const
{
    return m_rotation;
}
