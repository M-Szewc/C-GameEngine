#include "logger.h"
#include "asserts.h"
#include "platform/platform.h"

// TODO: remove temporary
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
    const char* level_strings[6] = {"[FATAL]:", "[ERROR]:", "[WARN]:", "[INFO]:", "[DEBUG]:", "[TRACE]:"};
    b8 is_error = level <= LOG_LEVEL_ERROR;

    // Technically imposes a 32k character limit on a single log entry, but no reasonable log is that long
    const i32 MAX_MSG_LENGTH = 32000;
    char out_message[MAX_MSG_LENGTH];
    platform_zero_memory(out_message, sizeof(out_message));

    // Format original message
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, MAX_MSG_LENGTH, message, arg_ptr);
    va_end(arg_ptr);

    char final_message[MAX_MSG_LENGTH];
    sprintf(final_message, "%s %s\n", level_strings[level], out_message);

    // platform-specific output
    if (is_error) {
        platform_console_write_error(final_message, level);
    } else {
        platform_console_write(final_message, level);
    }
}

void report_assertion_failure_msg(const char* expression, const char* message, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line %d\n", expression, message, file, line);
}

void report_assertion_failure(const char* expression, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, in file: %s, line %d\n", expression, file, line);
}