/*
   parser.hpp - //lib/casyt.parse

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/parse/parse_error.hpp>
#include <casyt/parse/parser.hpp>

using casyt::lexer_token;

void casyt::parser::parse() {
    lexer_token t;

    _lexer >> t;
    _tokens.emplace_back(t);
}
