#include "Parser.hpp"

void Parser::parseOperands(const Lexer &lexer) {
	std::vector<std::string> operands = lexer.getOperands();

	try {
		for (long unsigned int i = 0; i < operands.size(); i++) {
			cout << operands[i] << endl;
		}

	} catch(std::regex_error& e) {
		cout << "regex_error caught: " << e.what() << endl;;
	}
}