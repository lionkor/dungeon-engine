#ifndef GLOBAL_H
#define GLOBAL_H

#ifndef DEBUG
#define DEBUG 1
#endif // DEBUG
#ifndef VERBOSE_DBG
#define VERBOSE_DBG 1
#endif // VERBOSE_DBG
#ifndef DEBUG_TO_FILE
#define DEBUG_TO_FILE 0
#endif

#include <utility>
#include <cassert>
#include <experimental/filesystem>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

#include "String/String.h"

#include <string.h>
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if DEBUG

#if VERBOSE_DBG
#define verbose(x)                                                                  \
    std::cout << ANSI_BOLD << "VERBOSE " << __FILENAME__ << ":" << __LINE__ << ": " \
              << ANSI_RESET << x << std::endl
#else
#define verbose(x)
#endif // VERBOSE_DBG

#undef LOG
#define LOG(x)                                                                       \
    std::cout << ANSI_CYAN_BOLD << "LOG " << __FILENAME__ << ":" << __LINE__ << ": " \
              << ANSI_RESET << x << std::endl
#endif // DEBUG

#define ERROR(x)                                                                      \
    std::cout << ANSI_RED_BOLD << "ERROR " << __FILENAME__ << ":" << __LINE__ << ": " \
              << ANSI_RESET << x << std::endl

#if DEBUG_TO_FILE
#include <fstream>
#define DEFINE_LOGSTREAM std::ofstream logstream = std::ofstream("tests/tests.log", std::ios::trunc | std::ios::out)
extern std::ofstream logstream;
#undef LOG
#define LOG(x) logstream << "LOG " << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << ": " << x << std::endl
#undef verbose
#define verbose(x) logstream << "VERBOSE " << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << ": " << x << std::endl;
#endif // DEBUG_TO_FILE

enum class BackendImplementation
{
    SFML,
    GL
};

#endif // GLOBAL_H
