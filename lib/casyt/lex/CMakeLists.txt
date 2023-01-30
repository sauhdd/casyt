#   /lib/casyt/lex/CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_library(casyt.lex STATIC
    lexer_position.cpp
    lexer_token.cpp
    lexer.cpp)

target_include_directories(casyt.lex PUBLIC
    ${CASYT_INCLUDE_DIR})

add_executable(casyt.lex-driver
    lexer.driver.cpp)

target_include_directories(casyt.lex-driver PUBLIC
    ${CASYT_INCLUDE_DIR})

target_link_libraries(casyt.lex-driver PUBLIC
    casyt.lex)
