#pragma once
#include <vector>
#include <string>
#include <regex>
#include <iostream>

class Lexer {

public:
	Lexer();
	bool RegularResult(std::vector<std::string> const & lines) const;
	~Lexer();
	
private:
	bool result;
};
