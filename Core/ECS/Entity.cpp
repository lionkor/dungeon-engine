#include "Entity.h"

Entity::Entity(State& state)
    : m_state(state)
{
}

Entity::~Entity()
{
}

void Entity::update(float)
{
    std::cout << int_guid() << std::endl;
}
