/*
   lexer_position.hpp - //lib/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <cstddef>

namespace casyt {

    struct lexer_position {
        std::size_t index = 0;
        std::size_t line = 0;
        std::size_t column = 0;

        lexer_position() = default;
        lexer_position(std::size_t &&, std::size_t &&, std::size_t &&);
        ~lexer_position() = default;
    };

    lexer_position &operator<<(lexer_position &, char);
}
