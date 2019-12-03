#pragma once

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include "MyException.hpp"
#include "Lexer.hpp"

using std::cout;
using std::endl;

class Parser {
	public:
	Parser() = default;
	~Parser() = default;

	void parseLines(std::vector<Line> &line);
	void parseOperands(std::vector<Line> &line);
	void extractValue(std::vector<Line> &line) const;
	bool validateSize(std::string line, eOperandType type) const;
	std::string commandToString(::instructions type) const;
	std::string stringRepresentation(::eOperandType e) const;

	private:
	std::vector<std::string> instructions;
};