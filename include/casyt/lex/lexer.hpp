/*
   lexer.hpp - //lib/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <casyt/lex/lexer_position.hpp>
#include <casyt/lex/lexer_token.hpp>

#include <string>

namespace casyt {

    class lexer {
      protected:
        std::string _source;
        lexer_position _position;
        char _character;

      public:
        lexer(std::string const &);
        ~lexer() = default;

        lexer &operator++();
        bool operator>>(lexer_token &);
    };
}
