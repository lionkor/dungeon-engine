#ifndef GUID_H
#define GUID_H

#include <functional>

using ptr_t = std::uintptr_t;

class GUID
{
public:
    GUID();
    ~GUID();
    
    GUID& guid();

    constexpr const GUID& guid() const { return *this; }

    constexpr ptr_t int_guid() const { return m_raw; }

    constexpr bool operator<(const GUID& other) const { return m_raw < other.m_raw; }

    constexpr bool operator>(const GUID& other) const { return m_raw > other.m_raw; }

    constexpr bool operator==(const GUID& other) const { return m_raw == other.m_raw; }

    constexpr bool operator<=(const GUID& other) const { return m_raw <= other.m_raw; }

    constexpr bool operator>=(const GUID& other) const { return m_raw >= other.m_raw; }

private:
    std::uintptr_t m_raw;
};

#endif // GUID_H
