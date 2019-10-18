#include "Lexer.hpp"
#include <regex>
#include <iostream>
Lexer::Lexer():
    result(false)
{};

Lexer::~Lexer() {}

bool Lexer::RegularResult(std::vector<std::string> const & lines) const{
    std::vector<std::string> newlines;

    std::regex ex1("^pop[\n\t]*;$");
    std::regex ex2("^dump$");
    std::regex ex3("^add$");
    std::regex ex4("^sub$");
    std::regex ex5("^mul$");
    std::regex ex6("^div$");
    std::regex ex7("^mod$");
    std::regex ex8("^print$");
    std::regex ex9("^exit$");
    for (int i = 0; i < lines.size(); i++)
    {
        if (std::regex_match(lines[i], ex1) || std::regex_match(lines[i], ex2) || std::regex_match(lines[i], ex3) || std::regex_match(lines[i], ex4) || 
        std::regex_match(lines[i], ex5) || std::regex_match(lines[i], ex6) || std::regex_match(lines[i], ex7) || std::regex_match(lines[i], ex8) || 
        std::regex_match(lines[i], ex9)) {
            newlines.push_back(lines[i]);
        }
    }
    // for (int i = 0; i < newlines.size(); ++i) {
	// 	std::cout << newlines[i] << std::endl;
	// }
    return this->result;
}