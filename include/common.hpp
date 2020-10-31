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

#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || defined(_WIN32) \
    || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) \
    || defined(__WIN64) || defined(__WIN64__)
//!Microsoft Windows
#define ELOGGER_EXPORT __declspec(dllexport)
#define ELOGGER_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//!Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define ELOGGER_EXPORT __attribute__((visibility("default")))
#define ELOGGER_IMPORT __attribute__((visibility("default")))
#define ELOGGER_HIDDEN __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define ELOGGER_EXPORT
#define ELOGGER_IMPORT
#pragma warning Unknown dynamic link import / export semantics.
#endif

#define _elogger_date_      __DATE__
#define _elogger_time_      __TIME__
#define _elogger_function_  __FUNCTION__
#define _elogger_line_      __LINE__
#define _elogger_file_      __FILE__
#define _elogger_counter_   __COUNTER__

#if defined (__APPLE__) && defined(__MACH__)
/* macOS */
#   define __ELOGGER_PLATFORM_OS__             "macOS"
#   define __ELOGGER_MAC            "Unix-macOS (X11)"
#   define __ELOGGER_PLATFORM_TYPE__           "Macintosh"
#elif defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define __ELOGGER_PLATFORM_OS__        "Linux"
#   define __ELOGGER_LINUX     "Linux"
#   define __ELOGGER_DEVICE                 "Desktop"
#   define __ELOGGER_PLATFORM_TYPE__      "Unix (Linux)"
#   elif defined (X64_64bit) && defined(__linux) && defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define __ELOGGER_PLATFORM_OS__        "Linux"
#   define __ELOGGER_LINUX     "Linux"
#   define __ELOGGER_DEVICE                 "Desktop"
#   define __ELOGGER_PLATFORM_TYPE__      "Unix (Linux)"
#elif defined(_WIN32) || defined(_WIN32_WINNT ) && !defined(_WIN64) && !defined (WINAPI_FAMILY_PHONE_APP) && !defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (32-bit). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "Windows"
#   define __ELOGGER_WINDOWS_X86              "Microsoft Windows (32-Bit)"
#   define __ELOGGER_WINDOWS                  "Microsoft Windows (32-Bit)"
#   define __ELOGGER_DEVICE                  "Desktop"
#   define __ELOGGER_PLATFORM_TYPE__            "PC (Windows)"
#elif defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT ) && !defined (WINAPI_FAMILY_PHONE_APP) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (64-bit). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "Windows "
#   define __ELOGGER_PLATFORM_ARCH__            "x64 (64-Bit)"
#   define __ELOGGER_WINDOWS_X64     "Microsoft Windows"
#   define __ELOGGER_DEVICE                 "Desktop"
#   define __ELOGGER_WINDOWS     "Microsoft Windows"
#   define __ELOGGER_PLATFORM_TYPE__            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
/* Microsoft Windows Store or Universal Windows Platform - (32-bit). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "Windows"
#   define __ELOGGER_WINDOWS_X86              "Microsoft Windows (32-Bit)"
#   define __ELOGGER_WINDOWS_UWP              "Microsoft Windows UWP (32-Bit)"
#   define __ELOGGER_DEVICE                  "Desktop"
#   define __ELOGGER_PLATFORM_TYPE__            "PC (Windows)"
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP) && defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT )
/* Microsoft Windows (64-bit). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "Windows "
#   define __ELOGGER_WINDOWS_X64              "Microsoft Windows x64"
#   define __ELOGGER_WINDOWS_UWP              "Microsoft Windows UWP"
#   define __ELOGGER_DEVICE                  "Desktop"
#   define __ELOGGER_WINDOWS                  "Microsoft Windows"
#   define __ELOGGER_PLATFORM_TYPE__            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "WindowsRT"
#   define __ELOGGER_WINDOWS_PHONE   "Windows Phone"
#   define __ELOGGER_DEVICE                   "Mobile"
#   define __ELOGGER_PLATFORM_TYPE__            "Mobile (Windows Phone)"
#   elif defined(_WIN64) && defined(WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define __ELOGGER_PLATFORM_OS__              "WindowsRT"
#   define __ELOGGER_DEVICE                   "Mobile"
#   define __ELOGGER_WINDOWS_PHONE   "Windows Phone"
#   define __ELOGGER_PLATFORM_TYPE__            "Mobile (Windows Phone)"
#endif

#define STR_NULL ""
#define newline '\n'

#endif // COMMON_HPP
