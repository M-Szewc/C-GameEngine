#include "logger.h"
#include "asserts.h"

// TODO: temporary, remove later
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging() {
  // TODO: create log file
  return true;
}

void shutdown_logging() {
  // TODO: cleanup logging/write queued entries
}

void log_output(log_level level, const char* message, ...) {
  const char* level_String[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
  b8 is_error = level < LOG_LEVEL_WARN;

  // TODO: technical limit of log size
  char format_buffer[MAX_LOG_MESSAGE_LENGTH];
  char out_message[MAX_LOG_MESSAGE_LENGTH];
  memset(format_buffer, 0, sizeof(format_buffer));
  memset(out_message, 0, sizeof(out_message));

  __builtin_va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(format_buffer, MAX_LOG_MESSAGE_LENGTH, message ,arg_ptr);
  va_end(arg_ptr);

  sprintf(out_message, "%s%s\n", level_String[level], format_buffer);

  // TODO: platform specific output
  printf("%s", out_message);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
  log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}
