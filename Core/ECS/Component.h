#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Global.h"

class Entity;

class Component
{
public:
    Component(Entity& entity) : m_entity(entity) {}
    virtual ~Component() {}

    Entity& entity() { return m_entity; }
    const Entity& entity() const { return m_entity; }

protected:
    Entity& m_entity;
};

#endif // COMPONENT_H
