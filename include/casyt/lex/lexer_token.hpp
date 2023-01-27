/*
   lexer_token.hpp - //lib/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <casyt/lex/lexer_position.hpp>

#include <string>

namespace casyt {

    struct lexer_token {
        std::string type;
        std::string value;
        lexer_position position;

        lexer_token(std::string const &, std::string const &, lexer_position const &);
        lexer_token() = default;
    };
}
