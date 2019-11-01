#pragma once

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include "MyException.hpp"

class Lexer {

public:
	Lexer();
	void RegularResult(const std::vector<std::string> & lines);
	std::vector<std::string> getValue() const;
	~Lexer() = default;
	
private:
	std::vector<std::string> value;
	bool exit_check;
};
