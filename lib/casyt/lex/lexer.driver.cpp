/*
   lexer.driver.cpp - //lib/casyt.lex

  Created at 2023-01-30 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer.hpp>
#include <casyt/lex/lexer_token.hpp>

#include <iostream>

int main(int argc, char const **argv) {
    if (argc < 2) {
        std::cerr << "\033[1;31merror:\033[0;0m expected a file input" << std::endl;

        return 1;
    }

    casyt::lexer lexer("");
    casyt::lexer_token token;

    return 0;
}
