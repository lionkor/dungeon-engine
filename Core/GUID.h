#ifndef GUID_H
#define GUID_H

#include <functional>

using ptr_t = std::uintptr_t;

class GUID
{
public:
    GUID();
    ~GUID();

    GUID(const GUID&);
    GUID(GUID&&);
    GUID& operator=(const GUID&);

    GUID& guid();

    constexpr const GUID& guid() const { return *this; }

    constexpr ptr_t int_guid() const { return m_raw; }

    constexpr bool operator<(const GUID& other) const { return m_raw < other.m_raw; }

    constexpr bool operator>(const GUID& other) const { return m_raw > other.m_raw; }

    constexpr bool operator==(const GUID& other) const { return m_raw == other.m_raw; }

    constexpr bool operator!=(const GUID& other) const { return !(*this == other); }

    constexpr bool operator<=(const GUID& other) const { return m_raw <= other.m_raw; }

    constexpr bool operator>=(const GUID& other) const { return m_raw >= other.m_raw; }

private:
    std::uintptr_t m_raw;
};

namespace std {
template<>
struct hash<GUID> {
    std::size_t operator()(const GUID& s) const noexcept { return s.int_guid(); }
};
} // namespace std

#endif // GUID_H
