#pragma once

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point types
typedef float f32;
typedef double f64;

// boolean
typedef unsigned int b32;
typedef unsigned char b8;

// Properly define static assertions
#if defined(__clang__) || defined(__gcc__)
    #define GE_STATIC_ASSERT _Static_assert
#else
    #define GE_STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
GE_STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
GE_STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
GE_STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
GE_STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

GE_STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
GE_STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
GE_STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
GE_STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

GE_STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
GE_STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

GE_STATIC_ASSERT(sizeof(b8) == 1, "Expected b8 to be 1 byte.");
GE_STATIC_ASSERT(sizeof(b32) == 4, "Expected b32 to be 4 bytes.");

#define true 1
#define false 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
// Windows OS
    #define GE_PLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
#elif defined(__linux__) || defined(__gnu_linux)
// Linux OS
    #define GE_PLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define GE_PLATFORM_ANDROID 1
    #endif
#elif defined(_POSIX_VERSION)
// Posix
    #define GE_PLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
    #define GE_PLATFORM_APPLE 1
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
    // IOS Simulator
        #define GE_PLATFORM_IOS 1
        #define GE_PLATFORM_IOS_SIMULATOR 1
    #elif TARGET_OS_IPHONE
    // IOS device
        #define GE_PLATFORM_IOS 1
    #elif TARGET_OS_MAC
    // Other kinds of Mac OS
    #else
        #error "Unknown Apple platform"
    #endif
#else
    #error "Unknown platform!"
#endif

#ifdef GE_EXPORT
// Exports
    #ifdef _MSC_VER
        #define GE_API __declspec(dllexport)
    #else
        #define GE_API __attribute__((visibility("default")))
    #endif
#else
// Imports
    #ifdef _MSC_VER
        #define GE_API __declspec(dllimport)
    #else
        #define GE_API
    #endif
#endif