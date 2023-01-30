/*
   lexer.test.cpp - //tests/casyt.lex

  Created at 2023-01-26 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer.hpp>
#include <casyt/lex/lexer_token.hpp>

#include <gtest/gtest.h>

#include <iostream>
#include <vector>

TEST(lexer, all) {
    casyt::lexer lexer("a::b(\"c\", ::d) { e = [1, 2, 3] }");
    casyt::lexer_token token("type", "value", casyt::lexer_position());

    std::vector<casyt::lexer_token> tokens;

    while (lexer >> token) {
        tokens.emplace_back(token);
    }

    EXPECT_EQ(tokens.at(0).value, "a");
    EXPECT_EQ(tokens.at(1).value, "::");
    EXPECT_EQ(tokens.at(2).value, "b");
    EXPECT_EQ(tokens.at(3).value, "(");
    EXPECT_EQ(tokens.at(4).value, "c");
    EXPECT_EQ(tokens.at(5).value, ",");
    EXPECT_EQ(tokens.at(6).value, "::");
    EXPECT_EQ(tokens.at(7).value, "d");
    EXPECT_EQ(tokens.at(8).value, ")");
    EXPECT_EQ(tokens.at(9).value, "{");
    EXPECT_EQ(tokens.at(10).value, "e");
    EXPECT_EQ(tokens.at(11).value, "=");
    EXPECT_EQ(tokens.at(12).value, "[");
    EXPECT_EQ(tokens.at(13).value, "1");
    EXPECT_EQ(tokens.at(14).value, ",");
    EXPECT_EQ(tokens.at(15).value, "2");
    EXPECT_EQ(tokens.at(16).value, ",");
    EXPECT_EQ(tokens.at(17).value, "3");
    EXPECT_EQ(tokens.at(18).value, "]");
    EXPECT_EQ(tokens.at(19).value, "}");
}
