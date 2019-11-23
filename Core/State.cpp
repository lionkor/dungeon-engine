#include "State.h"

Application& State::application() { return m_application; }

const Application& State::application() const { return m_application; }

void State::adopt_entity(OwnPtr<Entity>&& ptr)
{
    m_entities.emplace(std::pair { ptr->int_guid(), std::move(ptr) });
}

RawPtr<Entity> State::get_entity(GUID guid) { NOTIMPL }
