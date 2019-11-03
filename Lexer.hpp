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
	~Lexer() = default;

	void RegularResult(const std::vector<std::string> & lines);
	std::vector<std::string> getOperands() const;
	std::vector<std::string> getInstructions() const;
	bool getExit() const;
	
private:
	std::vector<std::string> operands;
	std::vector<std::string> instructions;
	bool exit_check;
};
