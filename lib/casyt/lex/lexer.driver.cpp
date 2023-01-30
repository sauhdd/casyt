/*
   lexer.driver.cpp - //lib/casyt.lex

  Created at 2023-01-30 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/lex/lexer.hpp>
#include <casyt/lex/lexer_token.hpp>

#include <cstddef>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <vector>

int main(int argc, char const **argv) {
    if (argc < 2) {
        std::cerr << "\033[1;31merror:\033[0;0m expected a file input" << std::endl;

        return 1;
    }

    if (!std::filesystem::is_regular_file(argv[1])) {
        std::cerr << "\033[1;31merror:\033[0;0m '\033[0;35m" << argv[1] << "\033[0;0m' is not a file" << std::endl;

        return 1;
    }

    std::ifstream file_stream(argv[1]);
    std::string file_content((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());

    casyt::lexer lexer(file_content);
    casyt::lexer_token token;

    while (lexer >> token) {
        std::cout << "lexer_token(\"" << token.type << "\", \"" << token.value << "\", lexer_position(I" << token.position.index << ", L"
                  << token.position.line << ", C" << token.position.column << "))" << std::endl;
    }

    return 0;
}
