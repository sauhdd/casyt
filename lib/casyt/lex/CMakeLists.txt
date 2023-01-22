#   /lib/casyt/lex/CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_library(casyt.lex STATIC
    lexer_position.cpp)

target_include_directories(casyt.lex PUBLIC
    ${CASYT_INCLUDE_DIR})
