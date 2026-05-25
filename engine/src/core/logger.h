#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for release builds
#if GE_RELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
  LOG_LEVEL_FATAL = 0,
  LOG_LEVEL_ERROR = 1,
  LOG_LEVEL_WARN  = 2,
  LOG_LEVEL_INFO  = 3,
  LOG_LEVEL_DEBUG = 4,
  LOG_LEVEL_TRACE = 5 
} log_level;

b8 initialize_logging();
void shutdown_logging();

#define MAX_LOG_MESSAGE_LENGTH 32000

GE_API void log_output(log_level level, const char* message, ...);

// Logs a fatal-level message.
#define GE_FATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#ifndef GE_ERROR
  // Logs a error-level message
  #define GE_ERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)
#endif

#if LOG_WARN_ENABLED == 1
  #ifndef GE_WARN
    // Logs a warn-level message
    #define GE_WARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
  #else
    #define GE_WARN(message, ...)
  #endif
#endif

#if LOG_INFO_ENABLED == 1
  #ifndef GE_INFO
    // Logs a info-level message
    #define GE_INFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
  #else
    #define GE_INFO(message, ...)
  #endif
#endif

#if LOG_DEBUG_ENABLED == 1
  #ifndef GE_DEBUG
    // Logs a debug-level message
    #define GE_DEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
  #else
    #define GE_DEBUG(message, ...)
  #endif
#endif

#if LOG_TRACE_ENABLED == 1
  #ifndef GE_TRACE
    // Logs a trace-level message
    #define GE_TRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
  #else
    #define GE_TRACE(message, ...)
  #endif
#endif
