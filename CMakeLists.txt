cmake_minimum_required(VERSION 4.3)
# If you have an older CMake version then check the appropriate CMAKE_EXPERIMENTAL_CXX_IMPORT_STD string

# IMPORTANT: Force Ninja generator for C++20 modules
if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
    message(FATAL_ERROR "C++20 modules require the Ninja generator. Use: cmake -G Ninja -B build")
endif()

# # Set to use libc++ on clang for module support (must be before project() so
# # CMake probes the compiler with libc++ and discovers the correct std module path)
# if(CMAKE_CXX_COMPILER MATCHES "clang")
#   set(CMAKE_CXX_FLAGS "-stdlib=libc++" CACHE STRING "" FORCE)
# endif()

# Use experimental gate UUID for CMake v4.3.0
# Set to the correct string for your CMake version (change v4.3.0 to your version):
# https://github.com/Kitware/CMake/blob/v4.3.0/Help/dev/experimental.rst
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

project(hello-modules CXX)

# Set the required C++ standard
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS ON)

# Scan for modules and enable import std for all targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_MODULE_STD ON)

# Create executable
add_executable(hello)
target_sources(hello
  PRIVATE
      main.cpp
  PRIVATE FILE_SET CXX_MODULES
    FILES
      Hello.cppm
      HelloImpl.cppm
  )
