#   /tests/casyt/lex/CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_executable(casyt.lex-test
    lexer_position.test.cpp
    lexer.test.cpp)

target_link_libraries(casyt.lex-test PUBLIC
    casyt.lex
    GTest::gtest_main)

target_include_directories(casyt.lex-test PUBLIC
    ${CASYT_INCLUDE_DIR})

gtest_discover_tests(casyt.lex-test)
