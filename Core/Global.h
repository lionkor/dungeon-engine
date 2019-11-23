#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

#include <utility>
#include <cassert>
#include <filesystem>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

using glm::vec2;
using SizeT = std::size_t;
using uchar = std::uint8_t;

template<typename _T>
using Vector = std::vector<_T>;

#include "DebugTools.h"
#include "GUID.h"
#include "Memory.h"
#include "RawPtr.h"

#include "../String/String.h"

static inline sf::String to_sf_string(const String& str)
{
    return sf::String(str.c_str());
}
static inline sf::String to_sf_string(const StringView& str)
{
    return sf::String(str.c_str());
}

#define VIRTUAL_DTOR(x, ...)                                                             \
public:                                                                                  \
    virtual ~x() __VA_ARGS__ {}

#endif // GLOBAL_H
