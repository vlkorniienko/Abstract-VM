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

    void parseCommands(const Lexer &lexer);

    private:
    std::vector<std::string> instructions;
};