#include "Entity.h"

Entity::Entity(State& state, vec2 position) : m_state(state), m_transform(*this, position)
{
}

Entity::~Entity()
{
}

void Entity::update(float)
{
    std::cout << int_guid() << std::endl;
}

Transform& Entity::transform()
{
    return m_transform;
}

const Transform& Entity::transform() const
{
    return m_transform;
}

State& Entity::state()
{
    return m_state;
}

const State& Entity::state() const
{
    return m_state;
}

void Entity::serialize(File& ifile)
{
    NOTIMPL
}

void Entity::deserialize(File& ofile)
{
    NOTIMPL
}
