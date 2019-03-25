#ifndef LEXER_HPP
# define LEXER_HPP
#include <vector>

class Lexer {

public:
	Lexer();
	bool RegularResult(std::vector<std::string> lines);
	~Lexer();
	
private:
	bool result;
};

#endif