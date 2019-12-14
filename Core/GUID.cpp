#include "GUID.h"

GUID::GUID() : m_raw(reinterpret_cast<std::uintptr_t>(this))
{
}

GUID::~GUID()
{
}

GUID& GUID::guid()
{
    return *this;
}
