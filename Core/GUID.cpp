#include "GUID.h"

GUID::GUID()
    : m_raw(reinterpret_cast<std::uintptr_t>(this)) {
}

GUID::~GUID() {
}

GUID& GUID::guid() {
    return *this;
}

GUID::GUID(const GUID&)
    : m_raw(reinterpret_cast<std::uintptr_t>(this)) {
}

GUID::GUID(GUID&&)
    : m_raw(reinterpret_cast<std::uintptr_t>(this)) {
}

GUID& GUID::operator=(const GUID&) {
    m_raw = reinterpret_cast<std::uintptr_t>(this);
    return *this;
}
