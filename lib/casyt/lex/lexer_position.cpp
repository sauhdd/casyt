/*
   lexer_position.cpp - //lib/casyt.lex

  Created at 2023-01-21 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer_position.hpp>

casyt::lexer_position::lexer_position() : index(0), line(0), column(0) {}

casyt::lexer_position::lexer_position(std::size_t &&index, std::size_t &&line, std::size_t &&column) : index(index), line(line), column(column) {}

casyt::lexer_position &casyt::operator<<(casyt::lexer_position &p, char c) {
    ++p.index;

    if (c == '\n') {
        ++p.line;
        p.column = 0;
    } else {
        ++p.column;
    }

    return p;
}
