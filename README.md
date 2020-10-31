# eLogger
eLogger is a modern efficient **cross-platform** logger

**Note :** This library is not yet complete and conceptually under development.

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/Kambiz-Asadzadeh/Kavenegar.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Kambiz-Asadzadeh/RestService/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Kambiz-Asadzadeh/Kavenegar.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Kambiz-Asadzadeh/RestService/context:cpp)
![Language iso: C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Version](https://img.shields.io/badge/Version-0.4-lightgrey)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux%20%7C%20iOS%20%7C%20Android%20%7C%20Web-lightgrey)
![Dependencies](https://img.shields.io/badge/dependencies-Curl%20%7C%20RapidJson-yellow)

## Installation
<p>
First of all, You need to make sure that curl library is installed on your development environment. So it may have some problems!
</p>

## Building

- You need CMake tool for building source code
- All source code is written with Pure STL 1z (C++17)
- MSVC 2017, GCC8.x or Clang 9.x
- Add eLogger.dll [on Windows], libeLogger.dylib [on macOS] or libeLogger.so [on Linux] for your project as external library. you can compile it by static mode.
- Import SDK common header ```#include <eLogger>```

**Note:** In order to build the create, your compiler must support C++17 features.

**Building extra option in CMake**
```
cmake .. -DENABLE_SAFE_ONLY=true 
cmake .. -DENABLE_SAFTY_MODE=true 
```

## Usage Example

## Contribution
Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com

## **ToDo**
 * And more features...
