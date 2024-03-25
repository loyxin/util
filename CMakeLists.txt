cmake_minimum_required(VERSION 3.14...3.21)

set(PROJECT_NAME LoyUtil)
project(${PROJECT_NAME})

if(${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
  message(FATAL_ERROR "Source Build no allow")
endif()

include_directories(${PROJECT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# -----------------------------------------------------------------------------
# Options. Turn on with 'cmake -Dtest=ON'.
# -----------------------------------------------------------------------------
option(test "Build all tests." ON)
# not implement
option(coverage "gcov generate coverage report" OFF)

# -----------------------------------------------------------------------------
# Compiler config
# -----------------------------------------------------------------------------
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -mavx512f")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

if(NOT CMAKE_BUILD_TYPE)
  if(test)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose Release or Debug" FORCE)
  else()
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
  endif()
endif()

# -----------------------------------------------------------------------------
# cmake config
# -----------------------------------------------------------------------------
include(${CMAKE_MODULE_PATH}/thirdparty.cmake)

# -----------------------------------------------------------------------------
# subdirectory
# -----------------------------------------------------------------------------
add_subdirectory(cmdoptions)
add_subdirectory(common)
