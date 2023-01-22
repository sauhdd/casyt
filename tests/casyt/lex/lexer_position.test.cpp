/*
   lexer_position.test.cpp - //tests/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer_position.hpp>

#include <gtest/gtest.h>

TEST(lexer_position, advance) {
    casyt::lexer_position p(0, 0, 0);

    p << ' ';

    EXPECT_EQ(p.index, 1);
    EXPECT_EQ(p.line, 0);
    EXPECT_EQ(p.column, 1);

    p << '\n';

    EXPECT_EQ(p.index, 2);
    EXPECT_EQ(p.line, 1);
    EXPECT_EQ(p.column, 0);
}
