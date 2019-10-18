#include "Lexer.hpp"

Lexer::Lexer():
    result(false)
{};

Lexer::~Lexer() {}

bool Lexer::RegularResult(std::vector<std::string> const & lines) const {
    std::vector<std::string> newlines;

    std::regex ex1("(^pop$)|(^pop\\s*;.*$)");
    std::regex ex2("(^dump$)|(^dump\\s*;.*$)");
    std::regex ex3("(^add$)|(^add\\s*;.*$)");
    std::regex ex4("(^sub$)|(^sub\\s*;.*$)");
    std::regex ex5("(^mul$)|(^mul\\s*;.*$)");
    std::regex ex6("(^div$)|(^div\\s*;.*$)");
    std::regex ex7("(^mod$)|(^mod\\s*;.*$)");
    std::regex ex8("(^print$)|(^print\\s*;.*$)");
    std::regex ex9("(^exit$)|(^exit\\s*;.*$)");
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i] == "")
            continue;
        if (lines[i].length() > 2 && lines[i].at(0) == ';' && lines[i].at(1) != ';')
            continue;
        if (std::regex_match(lines[i], ex1) || std::regex_match(lines[i], ex2) || std::regex_match(lines[i], ex3) || std::regex_match(lines[i], ex4) || 
        std::regex_match(lines[i], ex5) || std::regex_match(lines[i], ex6) || std::regex_match(lines[i], ex7) || std::regex_match(lines[i], ex8) || 
        std::regex_match(lines[i], ex9)) {
            newlines.push_back(lines[i]);
        }
    }
    
    for (int i = 0; i < newlines.size(); ++i) {
		std::cout << newlines[i] << std::endl;
	}
    return this->result;
}