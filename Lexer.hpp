#pragma once
#include <vector>
#include <string>

class Lexer {

public:
	Lexer();
	bool RegularResult(std::vector<std::string> const & lines) const;
	~Lexer();
	
private:
	bool result;
};
