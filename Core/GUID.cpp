#include "GUID.h"

GUID::GUID()
    : m_raw(reinterpret_cast<std::uintptr_t>(this))
{
}

GUID::~GUID()
{
    if (m_destroy_callback)
        m_destroy_callback(m_raw);
}

bool GUID::has_destroy_callback() const 
{ 
    return m_destroy_callback != nullptr; 
}

GUID &GUID::guid()
{
    return *this;
}
