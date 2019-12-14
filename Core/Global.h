#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1
#define VERBOSE_DBG 1

#include <utility>
#include <cassert>
#include <experimental/filesystem>
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

template<typename _T, SizeT size>
using Array = std::array<_T, size>;

#include "DebugTools.h"
#include "GUID.h"
#include "Memory.h"
#include "RawPtr.h"

#include "../String/String.h"

#if VERBOSE_DBG
#define verbose(x) std::cout << ANSI_BOLD << "VERBOSE: " << x << ANSI_RESET << std::endl
#else
#define verbose(x)
#endif

enum class BackendImplementation
{
    SFML,
};

#endif // GLOBAL_H
