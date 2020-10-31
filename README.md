# eLogger
eLogger is a modern efficient **cross-platform** logger


**Platform Support**
- [x] Windows
- [x] macOS
- [x] Linux
- [ ] FreeBSD (ToDo...)
- [ ] Android (ToDo...)
- [ ] iOS (ToDo...)

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
Just add into your project :) And go on!
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

- You can set logger state by building tools variable such as CMake or QMake by ```ELOGGER_BUILD_DEBUG_MODE``` variable.
```
CMAKE:
set(ELOGGER_BUILD_DEBUG_MODE true)
QMAKE:
DEFINES += ELOGGER_BUILD_DEBUG_MODE
```
- Or you can set this option as c++ boolian type
```cpp
DeveloperMode::IsEnable = true; //false means you can't print any logs.
```
- You can specify the settings of log level:

```cpp
eLogger::Logger::LoggerModel = eLogger::Mode::User;
```

- And then, you can check developer mode if it was enable!

```cpp
if(isset(DeveloperMode::IsEnable)) {
        eLogger::Log("Info Message      : " , LoggerType::Info);
        eLogger::Log("Default Message   : " , LoggerType::Default);
        eLogger::Log("Warning Message   : " , LoggerType::Warning);
        eLogger::Log("Paused Message    : " , LoggerType::Paused);
        eLogger::Log("Success Message   : " , LoggerType::Success);
        eLogger::Log("Progress Message  : " , LoggerType::InProgress);
        eLogger::Log("Failed Message    : " , LoggerType::Failed);
        eLogger::Log("Done Message      : " , LoggerType::Done);
}
```
## Full Example of usage

```cpp

#include <iostream>
#include <eLogger>

using namespace eLogger;

int main()
{

    DeveloperMode::IsEnable = true;

    eLogger::Logger::LoggerModel = eLogger::Mode::Developer;

    if(isset(DeveloperMode::IsEnable)) {
        eLogger::Log("Info Message      : " , LoggerType::Info);
        eLogger::Log("Default Message   : " , LoggerType::Default);
        eLogger::Log("Warning Message   : " , LoggerType::Warning);
        eLogger::Log("Paused Message    : " , LoggerType::Paused);
        eLogger::Log("Success Message   : " , LoggerType::Success);
        eLogger::Log("Progress Message  : " , LoggerType::InProgress);
        eLogger::Log("Failed Message    : " , LoggerType::Failed);
        eLogger::Log("Done Message      : " , LoggerType::Done);
    }

    return 0;
}
```
## Output as User mode:
```
 => Log Id : [0] : [Info] Info Message      :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [1] : [Default] Default Message   :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [2] : [Warning] Warning Message   :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [3] : [Paused] Paused Message    :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [4] : [Success] Success Message   :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [5] : [InProgress] Progress Message  :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [6] : [Failed] Failed Message    :  { DateTime: 2020/11/01 01:48:19 }
 => Log Id : [7] : [Done] Done Message      :  { DateTime: 2020/11/01 01:48:19 }
 ```
 ## Output as Developer mode:
```
 => Log Id : [0][ Line : 15] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Info] Info Message      :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [1][ Line : 16] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Default] Default Message   :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [2][ Line : 17] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Warning] Warning Message   :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [3][ Line : 18] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Paused] Paused Message    :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [4][ Line : 19] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Success] Success Message   :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [5][ Line : 20] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [InProgress] Progress Message  :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [6][ Line : 21] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Failed] Failed Message    :  { DateTime: 2020/11/01 01:49:29 }
 => Log Id : [7][ Line : 22] [ Function : main] [ Thread Id : 0x10c54edc0] [ File : ../TestWebService/main.cpp] ] : [Done] Done Message      :  { DateTime: 2020/11/01 01:49:29 }
```
## Contribution
Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com

## **ToDo**
 * And more features...
