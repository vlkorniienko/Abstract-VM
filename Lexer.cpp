#include "Lexer.hpp"
#include <regex>
#include <iostream>
Lexer::Lexer():
    result(false)
{};

Lexer::~Lexer() {}

bool Lexer::RegularResult(std::vector<std::string> lines) {

    std::regex ex1("^.pop.$");
    std::regex ex2("^.dump.$");
    std::regex ex3("^.add.$");
    std::regex ex4("^.sub.$");
    std::regex ex5("^.mul.$");
    std::regex ex6("^.div.$");
    std::regex ex7("^.mod.$");
    std::regex ex8("^.print.$");
    std::regex ex9("^.exit.$");
    for (int i = 0; i < lines.size(); i++)
    {
        if (std::regex_match(lines[i], ex1))
            std::cout << "Match found! " << std::endl;
    }
    return this->result;
}