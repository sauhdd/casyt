#   /lib/casyt/CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_subdirectory(lex)

add_library(casyt.driver STATIC
    driver.cpp)

target_include_directories(casyt.driver PUBLIC
    ${CASYT_INCLUDE_DIR})
