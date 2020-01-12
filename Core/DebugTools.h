#ifndef DEBUGTOOLS_H
#define DEBUGTOOLS_H

#include <cstdio>
#include <cstdlib>

#define ANSI_RESET "\u001b[0m"

#define ANSI_BLACK "\u001b[30m"
#define ANSI_RED "\u001b[31m"
#define ANSI_GREEN "\u001b[32m"
#define ANSI_YELLOW "\u001b[33m"
#define ANSI_BLUE "\u001b[34m"
#define ANSI_MAGENTA "\u001b[35m"
#define ANSI_CYAN "\u001b[36m"
#define ANSI_WHITE "\u001b[37m"

#define ANSI_BLACK_BOLD "\u001b[30;1m"
#define ANSI_RED_BOLD "\u001b[31;1m"
#define ANSI_GREEN_BOLD "\u001b[32;1m"
#define ANSI_YELLOW_BOLD "\u001b[33;1m"
#define ANSI_BLUE_BOLD "\u001b[34;1m"
#define ANSI_MAGENTA_BOLD "\u001b[35;1m"
#define ANSI_CYAN_BOLD "\u001b[36;1m"
#define ANSI_WHITE_BOLD "\u001b[37;1m"

#define ANSI_BOLD "\u001b[1m"
#define ANSI_UNDERLINE "\u001b[4m"

#ifndef NOTIMPL
#define NOTIMPL                                                                    \
    fprintf(stderr, "%s%s called but not implemented / unfinished in %s%s:%u%s\n", \
        ANSI_YELLOW, __PRETTY_FUNCTION__, ANSI_BOLD, __FILE__, __LINE__,           \
        ANSI_RESET);

#endif // NOTIMPL

#ifndef ASSERT
#define ASSERT(cond) _assert(__FILE__, __PRETTY_FUNCTION__, __LINE__, #cond, (cond))
#define ASSERT_NOT_REACHABLE() _assert(__FILE__, __PRETTY_FUNCTION__, __LINE__, "reached unreachable code", false)

inline void _assert(const char* file, const char* function, unsigned line,
    const char* condition_string, bool result) {
    if (!result) {
#if DEBUG
        fprintf(stderr,
            "%sASSERTION FAILED%s at %s%s:%u%s \n\t-> in %s%s%s, Line %u: \n\t\t-> "
            "Failed Condition: %s%s%s\n",
            ANSI_RED_BOLD, ANSI_RESET, ANSI_UNDERLINE, file, line, ANSI_RESET,
            ANSI_BOLD, function, ANSI_RESET, line, ANSI_RED, condition_string,
            ANSI_RESET);
        fprintf(stderr, "%s... terminating with SIGABRT ...%s\n", ANSI_BOLD, ANSI_RESET);
        abort();
#else
        fprintf(stderr,
            "%s=> ASSERTION `%s` FAILED IN RELEASE BUILD%s%s -> IGNORING FAILED ASSERTION "
            "& HOPING IT WON'T CRASH%s\n",
            ANSI_RED_BOLD, condition_string, ANSI_RESET, ANSI_RED, ANSI_RESET);
#endif
    }
}

#endif

#endif // DEBUGTOOLS_H
