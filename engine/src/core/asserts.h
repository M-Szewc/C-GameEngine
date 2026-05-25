#pragma once

#include "defines.h"

// Disable assertions by commenting out this line
#define GE_ASSERTIONS_ENABLED

#ifdef GE_ASSERTIONS_ENABLED

#if _MSC_VER
  #include <intrin.h>
  #define debugBreak() __debugbreak()
#else // TODO: add settings for other IDEs
  #define debugBreak() __builtin_trap()
#endif

GE_API void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define GE_ASSERT(expr)                                     \
{                                                           \
  if (expr){                                                \
  } else {                                                  \
    report_assertion_failure(#expr, "", __FILE__, __LINE__);\
    debugBreak();                                           \
  }                                                         \
}

#define GE_ASSERT_MSG(expr, message)                                     \
{                                                                 \
  if (expr){                                                      \
  } else {                                                        \
    report_assertion_failure(#expr, message, __FILE__, __LINE__); \
    debugBreak();                                                 \
  }                                                               \
}

#ifdef _DEBUG
#define GE_ASSERT_DEBUG(expr)                               \
{                                                           \
  if (expr){                                                \
  } else {                                                  \
    report_assertion_failure(#expr, "", __FILE__, __LINE__);\
    debugBreak();                                           \
  }                                                         \
}
#else
#define GE_ASSERT_DEBUG(expr) // Does nothing outside debug mode
#endif

#else // Assertions disabled

#define GE_ASSERT(expr)
#define GE_ASSERT_MSG(expr)
#define GE_ASSERT_DEBUG(expr)

#endif
