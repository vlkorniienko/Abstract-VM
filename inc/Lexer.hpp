#pragma once

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include "MyException.hpp"
#include "Line.hpp"

class Lexer {

public:
	Lexer();
	~Lexer() = default;

	void				RegularResult(const std::vector<std::string> & lines);
	std::vector<Line>	getLineVector() const;
	bool				getExit() const;
	int					getDelLines() const;
	
private:
	std::vector<Line>	lineVector;
	bool				exit_check;
	bool				findErrInValue(std::string line);
};
