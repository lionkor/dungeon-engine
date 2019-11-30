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
    virtual ~Entity() override;

    virtual void update(float);

    Transform& transform();
    const Transform& transform() const;

    State& state();
    const State& state() const;

    template<typename _T, typename... _Args>
    auto& add_component(_Args&&... args);

protected:
    State& m_state;
    Transform m_transform;
    Vector<RefPtr<Component>> m_components;

    // Serializable interface
public:
    virtual void serialize(File&) override;
    virtual void deserialize(File&) override;
};

template<typename _T, typename... _Args>
auto& Entity::add_component(_Args&&... args)
{
    // FIXME: Make sure we don't add components that already exist
    auto c = RefPtr<Component>(new _T(*this, std::forward(args)...));
    ASSERT(c.is_not_null());
    m_components.push_back(c);
    return reinterpret_cast<_T&>(*c);
}

#endif // ENTITY_H
