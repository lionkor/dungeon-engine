#ifndef STATE_H
#define STATE_H

#include "Global.h"
#include "ECS/Entity.h"

class State
{
public:
    State() : m_entities(0) {}
    virtual ~State() {}

    virtual void update(float dt) = 0;

    template<typename _EntityT, typename... _Args>
    void adopt_entity(_Args&&... args)
    {
        auto e = _EntityT::construct(*this, std::forward(args)...);
        m_entities.emplace(std::pair { e->guid(), std::move(e) });
    }
    RawPtr<Entity> get_entity(GUID guid);

protected:
    UnorderedMap<GUID, OwnPtr<Entity>> m_entities;
};

#endif // STATE_H
