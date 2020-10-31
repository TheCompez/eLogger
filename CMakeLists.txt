cmake_minimum_required(VERSION 3.5)

project(eLogger LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
option(ENABLE_SAFE_ONLY "Enable the building for safty codes only!" FALSE)
option(ENABLE_SAFTY_MODE "Enable safety warning mode reporting for compilers." FALSE)

if(ENABLE_SAFE_ONLY)
    SET (CMAKE_CXX_FLAGS "-Werror")
endif()

if(ENABLE_SAFTY_MODE)
    SET (CMAKE_CXX_FLAGS "-Wall")
endif()

set(CPP_HEADER *hpp)
set(CPP_SOURCE *.cpp)

file(GLOB_RECURSE SRCS ${CPP_HEADER} ${CPP_SOURCE})

add_library(eLogger STATIC
  ${SRCS}
)

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
SET(EXECUTABLE_OUTPUT_PATH ${dir})
SET(LIBRARY_OUTPUT_PATH ${dir}lib)
SET(CMAKE_CACHEFILE_DIR ${dir})

FIND_PACKAGE(CURL)
IF(CURL_FOUND)
  INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
  SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES} )
ELSE(CURL_FOUND)
  MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
ENDIF(CURL_FOUND)

target_include_directories(eLogger
  PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
