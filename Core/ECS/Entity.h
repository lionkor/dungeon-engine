#ifndef ENTITY_H
#define ENTITY_H

#include "../Global.h"
#include "Component.h"

class State;

class Entity : public GUID
{
public:
    Entity(State& state);
    virtual ~Entity();
    
    virtual void update(float);

protected:
    State& m_state;
    Vector<Component> m_components;
};

#endif // ENTITY_H
