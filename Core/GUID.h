#ifndef GUID_H
#define GUID_H

#include <functional>

using ptr_t = std::uintptr_t;

class GUID
{
public:
    GUID();
    ~GUID() noexcept;
    
    bool has_destroy_callback() const;
    
    template<typename _Fnc>
    inline void set_destroy_callback(_Fnc fnc) { m_destroy_callback = fnc; }
    
    GUID& guid();
    
    constexpr const GUID& guid() const;
    constexpr ptr_t int_guid() const;
    
    constexpr bool operator<(const GUID& other) const;
    constexpr bool operator>(const GUID& other) const;
    constexpr bool operator==(const GUID& other) const;
    constexpr bool operator<=(const GUID& other) const;
    constexpr bool operator>=(const GUID& other) const;
private:
    std::function<void(std::uintptr_t)> m_destroy_callback;
    std::uintptr_t m_raw;
};

#endif // GUID_H
