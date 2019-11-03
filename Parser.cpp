#include "Parser.hpp"


void Parser::parseCommands(const Lexer &lexer) {
    try {
      for (long unsigned int i = 0; i < lexer.getInstructions().size(); i++) {
        std::cout << lexer.getInstructions()[i] << std::endl;
      }

    } catch(std::regex_error& e) {
		cout << "regex_error caught: " << e.what() << endl;;
    }
}