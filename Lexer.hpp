#pragma once
#include <vector>
#include <string>
#include <regex>
#include <iostream>

class Lexer {

public:
	Lexer() = default;
	void RegularResult(const std::vector<std::string> & lines);
	std::vector<std::string> getValue() const;
	~Lexer() = default;
	
private:
	std::vector<std::string> value;
};
