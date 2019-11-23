#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

#include <utility>
#include <cassert>
#include <filesystem>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

using glm::vec2;
using SizeT = std::size_t;
using uchar = std::uint8_t;

template<typename _T>
using Vector = std::vector<_T>;

template<typename _T>
using UnorderedSet = std::unordered_set<_T>;

template<typename _KeyT, typename _ValueT>
using UnorderedMap = std::unordered_map<_KeyT, _ValueT>;

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

static inline sf::Vector2f to_sf_vector2f(const vec2& v)
{
    return sf::Vector2f(v.x, v.y);
}

#endif // GLOBAL_H
