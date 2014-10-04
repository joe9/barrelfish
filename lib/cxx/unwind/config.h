//===----------------------------- config.h -------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//
//  Defines macros used within libuwind project.
//
//===----------------------------------------------------------------------===//


#ifndef LIBUNWIND_CONFIG_H
#define LIBUNWIND_CONFIG_H

#include <assert.h>
#include <stdio.h>


// Define static_assert() unless already defined by compiler.
#ifndef __has_feature
  #define __has_feature(__x) 0
#endif
#if !(__has_feature(cxx_static_assert)) && !defined(static_assert)
  #define static_assert(__b, __m) ;
#endif

#ifdef __x86_64__
#undef __x86_64__
#define __x86_64__ 1
#endif

#ifdef __k1om__
#define __x86_64__ 1
#endif

// Platform specific configuration defines.
#if __APPLE__
  #include <Availability.h>
  #ifdef __cplusplus
    extern "C" {
  #endif
    void __assert_rtn(const char *, const char *, int, const char *)
                                                      __attribute__((noreturn));
  #ifdef __cplusplus
    }
  #endif

  #define _LIBUNWIND_BUILD_ZERO_COST_APIS (__i386__ || __x86_64__ || __arm64__)
  #define _LIBUNWIND_BUILD_SJLJ_APIS      (__arm__)
  #define _LIBUNWIND_SUPPORT_FRAME_APIS   (__i386__ || __x86_64__)
  #define _LIBUNWIND_EXPORT               __attribute__((visibility("default")))
  #define _LIBUNWIND_HIDDEN               __attribute__((visibility("hidden")))
  #define _LIBUNWIND_LOG(msg, ...) fprintf(stderr, "libuwind: " msg, __VA_ARGS__)
  #define _LIBUNWIND_ABORT(msg) __assert_rtn(__func__, __FILE__, __LINE__, msg)

  #if FOR_DYLD
    #define _LIBUNWIND_SUPPORT_COMPACT_UNWIND 1
    #define _LIBUNWIND_SUPPORT_DWARF_UNWIND   0
    #define _LIBUNWIND_SUPPORT_DWARF_INDEX    0
  #else
    #define _LIBUNWIND_SUPPORT_COMPACT_UNWIND 1
    #define _LIBUNWIND_SUPPORT_DWARF_UNWIND   1
    #define _LIBUNWIND_SUPPORT_DWARF_INDEX    0
  #endif

#else
  #include <stdlib.h>

  static inline void assert_rtn(const char* func, const char* file, int line, const char* msg)  __attribute__ ((noreturn));
  static inline void assert_rtn(const char* func, const char* file, int line, const char* msg) {
    printf("libunwind: %s %s:%d - %s\n",  func, file, line, msg);
    assert(false);
    abort();
  }


#if __USING_SJLJ_EXCEPTIONS__
  #define _LIBUNWIND_BUILD_ZERO_COST_APIS 0
  #define _LIBUNWIND_BUILD_SJLJ_APIS      1
#else
  #define _LIBUNWIND_BUILD_ZERO_COST_APIS 1
  #define _LIBUNWIND_BUILD_SJLJ_APIS      0
#endif
  #define _LIBUNWIND_SUPPORT_FRAME_APIS   1
  #define _LIBUNWIND_EXPORT               __attribute__((visibility("default")))
  #define _LIBUNWIND_HIDDEN               __attribute__((visibility("hidden")))
  #define _LIBUNWIND_LOG(msg, ...) printf(  "libuwind: " msg, __VA_ARGS__)
  #define _LIBUNWIND_ABORT(msg) assert_rtn(__func__, __FILE__, __LINE__, msg)

  #define _LIBUNWIND_SUPPORT_COMPACT_UNWIND 0
  #define _LIBUNWIND_SUPPORT_DWARF_UNWIND   1
  #define _LIBUNWIND_SUPPORT_DWARF_INDEX    0
#endif


// Macros that define away in non-Debug builds
#if 1
  #define _LIBUNWIND_DEBUG_LOG(msg, ...)
  #define _LIBUNWIND_TRACE_API(msg, ...)
  #define _LIBUNWIND_TRACING_UNWINDING 0
  #define _LIBUNWIND_TRACE_UNWINDING(msg, ...)
  #define _LIBUNWIND_LOG_NON_ZERO(x) x
#else
  #ifdef __cplusplus
    extern "C" {
  #endif
    extern  bool logAPIs(void);
    extern  bool logUnwinding(void);
  #ifdef __cplusplus
    }
  #endif
  #define _LIBUNWIND_DEBUG_LOG(msg, ...)  _LIBUNWIND_LOG(msg, __VA_ARGS__)
  #define _LIBUNWIND_LOG_NON_ZERO(x) \
            do { \
              int _err = x; \
              if ( _err != 0 ) \
                printf("libunwind::" #x "=%d in %s\n", _err, __func__); \
             } while (0)
  #define _LIBUNWIND_TRACE_API(msg...) \
            do { \
              printf(msg); \
            } while(0)
  #define _LIBUNWIND_TRACE_UNWINDING(msg...) \
            do { \
              printf("libunwind::" msg); \
            } while(0)
  #define _LIBUNWIND_TRACING_UNWINDING 1 /*logUnwinding() */
#endif


#endif // LIBUNWIND_CONFIG_H
