#pragma once

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include "MyException.hpp"
#include "Lexer.hpp"
#include "Line.hpp"

using std::cout;
using std::endl;

class Parser {
	public:
	Parser() = default;
	~Parser() = default;

	void parseLines(std::vector<Line> &line);
	void parseOperands(std::vector<Line> &line);
	void extractValue(std::vector<Line> &line) const;
	//std::string interpreter(::instructions type);

	private:
	std::vector<std::string> instructions;
};