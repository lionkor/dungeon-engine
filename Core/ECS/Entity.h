#ifndef ENTITY_H
#define ENTITY_H

#include "../Global.h"
#include "../IO/Serializable.h"
#include "Component.h"
#include "Transform.h"

class State;

class Entity : public GUID, public Serializable
{
public:
    // FIXME: pos 0,0 is probably not good
    Entity(State& state, vec2 position = { 0, 0 });
    virtual ~Entity();
    
    virtual void update(float);
                        
    Transform& transform();
    const Transform& transform() const;

protected:
    State& m_state;
    Transform m_transform;
    Vector<Component> m_components;
    
    // Serializable interface
public:
    virtual void serialize(File&) override;
    virtual void deserialize(File&) override;
};

#endif // ENTITY_H
