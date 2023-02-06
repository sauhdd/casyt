/*
   parser.hpp - //lib/casyt.parse

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <casyt/lex/lexer.hpp>
#include <casyt/lex/lexer_token.hpp>

#include <vector>

namespace casyt {

    using std::vector;

    class parser {
      protected:
        lexer _lexer;
        vector<lexer_token> _tokens;

      public:
        parser(lexer &l) : _lexer(l) {}
        ~parser() = default;

        void parse();
    };
}
