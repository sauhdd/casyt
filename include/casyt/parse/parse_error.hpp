/*
   parse_error.hpp - //lib/casyt.parse

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <casyt/lex/lexer_position.hpp>

#include <stdexcept>
#include <string>

namespace casyt {

    class parse_error : public std::runtime_error {
      public:
        lexer_position const &position;
        std::string const &message;

        parse_error(lexer_position const &position, std::string const &message)
            : position(position), message(message),
              runtime_error(message + " at " + std::to_string(position.line + 1) + ":" + std::to_string(position.column + 1)) {}

        ~parse_error() = default;
    };
}
