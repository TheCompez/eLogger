/*
  The MIT License (MIT)

  Copyright (c) 2020 Kambiz Asadzadeh

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>

constexpr  std::string_view __e_full_version  = "0.5";
constexpr  std::string_view __e_release_mode  = "alpha";
constexpr  std::string_view __e_release_mode_number  = "2";

//!Compiler Predefined Variables.

#define __e_null_str ""
#define __e_newline  "\n"
#define __e_compiler_counter            __COUNTER__
#define __e_compiler_line               __LINE__
#define __e_compiler_file               __FILE__
#define __e_compiler_function           __FUNCTION__
#define __e_compiler_pretty_function    __PRETTY_FUNCTION__
#define __e_compiled_date               __DATE__
#define __e_compiler_time               __TIME__

constexpr std::string_view __e_normal       = "\x1b[0m";
constexpr std::string_view __e_bold         = "\x1b[1m";
constexpr std::string_view __e_dim          = "\x1b[2m";
constexpr std::string_view __e_under_score  = "\x1b[4m";
constexpr std::string_view __e_blink        = "\x1b[5m";
constexpr std::string_view __e_reverse      = "\x1b[7m";
constexpr std::string_view __e_hidden       = "\x1b[8m";
constexpr std::string_view __e_reset        = "\x1b[0m";

#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || defined(_WIN32) \
    || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) \
    || defined(__WIN64) || defined(__WIN64__)
//!Microsoft Windows
#define __e_logger_export __declspec(dllexport)
#define __e_logger_import __declspec(dllimport)
#elif defined(__GNUC__)
//!Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __e_logger_export __attribute__((visibility("default")))
#define __e_logger_import __attribute__((visibility("default")))
#define __e_logger_hidden __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define __e_logger_export
#define __e_logger_import
#pragma warning Unknown dynamic link import / export semantics.
#endif

#if defined (__APPLE__) && defined(__MACH__)
/* macOS */
#   define __e_platform_os             "macOS"
#   define __e_mac            "Unix-macOS (X11)"
#   define __e_platform_type           "Macintosh"
#elif defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define __e_platform_os        "Linux"
#   define __e_linux     "Linux"
#   define __e_device                 "Desktop"
#   define __e_platform_type      "Unix (Linux)"
#   elif defined (X64_64bit) && defined(__linux) && defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define __e_platform_os        "Linux"
#   define __e_linux     "Linux"
#   define __e_device                 "Desktop"
#   define __e_platform_type      "Unix (Linux)"
#elif defined(_WIN32) || defined(_WIN32_WINNT ) && !defined(_WIN64) && !defined (WINAPI_FAMILY_PHONE_APP) && !defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (32-bit). ------------------------------ */
#   define __e_platform_os              "Windows"
#   define __e_windows_x86              "Microsoft Windows (32-Bit)"
#   define __e_windows                  "Microsoft Windows (32-Bit)"
#   define __e_device                  "Desktop"
#   define __e_platform_type            "PC (Windows)"
#elif defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT ) && !defined (WINAPI_FAMILY_PHONE_APP) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (64-bit). ------------------------------ */
#   define __e_platform_os              "Windows "
#   define __e_platform_arch            "x64 (64-Bit)"
#   define __e_windows_X64     "Microsoft Windows"
#   define __e_device                 "Desktop"
#   define __e_windows     "Microsoft Windows"
#   define __e_platform_type            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
/* Microsoft Windows Store or Universal Windows Platform - (32-bit). ------------------------------ */
#   define __e_platform_os              "Windows"
#   define __e_windows_x86              "Microsoft Windows (32-Bit)"
#   define __e_windows_UWP              "Microsoft Windows UWP (32-Bit)"
#   define __e_device                  "Desktop"
#   define __e_platform_type            "PC (Windows)"
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP) && defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT )
/* Microsoft Windows (64-bit). ------------------------------ */
#   define __e_platform_os              "Windows "
#   define __e_windows_X64              "Microsoft Windows x64"
#   define __e_windows_UWP              "Microsoft Windows UWP"
#   define __e_device                  "Desktop"
#   define __e_windows                  "Microsoft Windows"
#   define __e_platform_type            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define __e_platform_os              "WindowsRT"
#   define __e_windows_PHONE   "Windows Phone"
#   define __e_device                   "Mobile"
#   define __e_platform_type            "Mobile (Windows Phone)"
#   elif defined(_WIN64) && defined(WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define __e_platform_os              "WindowsRT"
#   define __e_device                   "Mobile"
#   define __e_windows_PHONE   "Windows Phone"
#   define __e_platform_type            "Mobile (Windows Phone)"
#endif

#define E_LOGGER_BRACE_BEGIN {
#define E_LOGGER_BRACE_END }
#define E_LOGGER_USING_NAMESPACE using namespace
#define E_LOGGER_NAMESPACE_BEGIN(x) namespace x {
#define ANONYMOUS_NAMESPACE_BEGIN namespace {
#define E_LOGGER_NAMESPACE_END }

#if defined(__clang__)
/* Clang/LLVM. ---------------------------------------------- */
#undef __e_compiler
#define __e_compiler "Clang/LLVM"
#undef __e_compiler_ver
#define __e_compiler_ver __clang_version__
#elif defined(__ICC) || defined(__INTEL_COMPILER)
/* Intel ICC/ICPC. ------------------------------------------ */
#define __e_compiler "Intel ICC/ICPC"
#define __e_compiler_ver __INTEL_COMPILER_BUILD_DATE
#elif defined(__MINGW32__) && !defined(__amd64__) && !defined(__amd64) && !defined(__ia64__)
/* __MINGW32__. ------------------------------------------------- */
#undef __e_compiler
#define __e_compiler "MinGW-w86 (x86) 32 Bit"
#undef __e_compiler_ver
#define __e_compiler_ver __MINGW32_MAJOR_VERSION << '.' << __MINGW32_MINOR_VERSION
#elif defined(__MINGW32__)
/* __MINGW32__. ------------------------------------------------- */
#undef __e_compiler
#define __e_compiler "MinGW-w64 (x86_64) 32-64 Bit"
#undef __e_compiler_ver
#define __e_compiler_ver __MINGW32_MAJOR_VERSION << '.' << __MINGW32_MINOR_VERSION
#elif defined(__MINGW64__)
/* __MINGW64__. ------------------------------------------------- */
#undef __e_compiler
#define __e_compiler "MinGW-w64 (x64) 64 Bit"
#undef __e_compiler_ver
#define __e_compiler_ver __MINGW64_MAJOR_VERSION << '.' << __MINGW64_MINOR_VERSION
#elif defined(__GNUC__) || defined(__GNUG__) && !defined(__clang__)
/* GNU GCC/G++. --------------------------------------------- */
#undef __e_compiler
#define __e_compiler "GNU GCC/G++"
#undef __e_compiler_ver
#define __e_compiler_ver __GNUC__
#elif defined(__HPPP_cc) || defined(__HPPP_aCC)
/* Hewlett-Packard C/aC++. ---------------------------------- */
#define __e_compiler "Hewlett-Packard C/aC++"
#define __e_compiler_ver __HPPP_aCC
#elif defined(__IBMC__) || defined(__IBMCPP__)
/* IBM XL C/C++. -------------------------------------------- */
#define __e_compiler "IBM XL C/C++"
#define __e_compiler_ver __xlC_veR
#elif defined(_MSC_VER)
/* Microsoft Visual Studio. --------------------------------- */
#undef __e_compiler
#define __e_compiler "MSVC++ "
#undef __e_compiler_MSVC
#define __e_compiler_MSVC
#undef __e_compiler_ver_
#define __e_compiler_ver _MSC_VER
#elif defined(__PGI)
/* Portland Group PGCC/PGCPP. ------------------------------- */
#define __e_compiler "PGCC/PGCPP"
#define __e_compiler_ver __VERSION__
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
/* Oracle Solaris Studio. ----------------------------------- */
#define __e_compiler "Oracle Solaris"
#define __e_compiler_ver __SUNPRO_CC
#endif

#endif // COMMON_HPP
