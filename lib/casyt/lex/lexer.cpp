/*
   lexer.cpp - //lib/casyt.lex

  Created at 2023-01-22 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer.hpp>
#include <casyt/lex/lexer_error.hpp>

#include <sstream>

casyt::lexer::lexer(std::string const &source) : _source(source + "\n"), _position(0, 0, 0) {
    if (_position.index >= source.length()) {
        throw casyt::lexer_error(_position, "source is empty");
    }

    _character = source.at(_position.index);
}

casyt::lexer &casyt::lexer::operator++() {
    if (_position.index + 1 >= _source.length()) {
        throw casyt::lexer_error(_position, "cannot advance");
    }

    _position << _character;
    _character = _source.at(_position.index);

    return *this;
}

bool casyt::lexer::operator>>(casyt::lexer_token &t) {
    while (std::string(" \n\t\r").find(_character) != std::string::npos) {
        try {
            operator++();
        } catch (casyt::lexer_error const &) {
            return false;
        }
    }

    casyt::lexer_position position = _position;

    if (std::string("qwertyuopasdfghjklizxcvbnm_").find(_character) != std::string::npos) {
        std::stringstream ss;

        while (std::string("qwertyuopasdfghjklizxcvbnm0123456789_").find(_character) != std::string::npos) {
            ss << _character;

            try {
                operator++();
            } catch (casyt::lexer_error const &) {
                return false;
            }
        }

        t.type = "identifier";
        t.value = ss.str();
        t.position = position;

        return true;
    } else if (std::string("0123456789").find(_character) != std::string::npos) {
        std::stringstream ss;

        while (std::string("0123456789").find(_character) != std::string::npos) {
            ss << _character;

            try {
                operator++();
            } catch (casyt::lexer_error const &) {
                return false;
            }
        }

        t.type = "integer";
        t.value = ss.str();
        t.position = position;

        return true;
    } else {
        switch (_character) {
            case '"': {
                std::stringstream ss;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                while (_character != '"') {
                    ss << _character;

                    try {
                        operator++();
                    } catch (casyt::lexer_error const &) {
                        return false;
                    }
                }

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                t.type = "string";
                t.value = ss.str();
                t.position = position;

                return true;
            }

            case '(': {
                t.type = "left_paranthesis";
                t.value = "(";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case ')': {
                t.type = "right_paranthesis";
                t.value = ")";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '[': {
                t.type = "left_bracket";
                t.value = "[";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case ']': {
                t.type = "right_bracket";
                t.value = "]";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '{': {
                t.type = "left_brace";
                t.value = "{";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '}': {
                t.type = "right_brace";
                t.value = "}";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case ',': {
                t.type = "comma";
                t.value = ",";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '=': {
                t.type = "equality_sign";
                t.value = "=";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '.': {
                t.type = "dot";
                t.value = ".";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case ':': {
                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                if (_character != ':') {
                    throw casyt::lexer_error(position, "unsupported semicolon");
                }

                t.type = "double_semicolon";
                t.value = "::";
                t.position = position;

                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                return true;
            }

            case '/': {
                try {
                    operator++();
                } catch (casyt::lexer_error const &) {
                    return false;
                }

                if (_character != '/') {
                    throw casyt::lexer_error(position, "unsupported slash");
                }

                while (_character != '\n') {
                    try {
                        operator++();
                    } catch (casyt::lexer_error const &) {
                        return false;
                    }
                }

                return true;
            }

            default: {
                throw casyt::lexer_error(position, "unsupported character");
            }
        }
    }
}
