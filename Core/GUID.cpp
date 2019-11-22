#include "GUID.h"

GUID::GUID()
    : m_raw(reinterpret_cast<std::uintptr_t>(this))
{
}

GUID::~GUID() noexcept
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

constexpr const GUID &GUID::guid() const
{
    return *this;
}

constexpr ptr_t GUID::int_guid() const
{
    return m_raw;
}

constexpr bool GUID::operator<(const GUID &other) const
{
    return m_raw < other.m_raw;
}

constexpr bool GUID::operator>(const GUID &other) const
{
    return m_raw > other.m_raw;
}

constexpr bool GUID::operator==(const GUID &other) const
{
    return m_raw == other.m_raw;
}

constexpr bool GUID::operator<=(const GUID &other) const
{
    return m_raw <= other.m_raw;
}

constexpr bool GUID::operator>=(const GUID &other) const
{
    return m_raw >= other.m_raw;
}
