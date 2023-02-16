/*
   parser.hpp - //lib/casyt.parse

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/parse/parse_error.hpp>
#include <casyt/parse/parser.hpp>

using casyt::context;
using casyt::lexer_token;
using casyt::target_info;

context casyt::parser::parse(target_info const &info) {
    lexer_token t;
    context ctx(info);

    _lexer >> t;
    _tokens.emplace_back(t);

    return ctx;
}
