#   /CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

cmake_minimum_required(VERSION 3.18)

project(Casyt
    VERSION 1.0
    DESCRIPTION "A tool for software development."
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CASYT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(Threads REQUIRED)

add_subdirectory(lib)
add_subdirectory(tools)
