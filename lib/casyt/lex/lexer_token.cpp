/*
   lexer_token.cpp - //lib/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer_token.hpp>

casyt::lexer_token::lexer_token(std::string const &type, std::string const &value, casyt::lexer_position const &position)
    : type(type), value(value), position(position) {}
