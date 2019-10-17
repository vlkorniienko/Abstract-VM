#pragma once
#include <vector>
#include <string>

class Lexer {

public:
	Lexer();
	bool RegularResult(std::vector<std::string> lines);
	~Lexer();
	
private:
	bool result;
};
