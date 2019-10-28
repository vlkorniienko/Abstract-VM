#include "Lexer.hpp"

void Lexer::RegularResult(const std::vector<std::string> & lines) {

	std::regex ex1("(^pop$)|(^pop\\s*;.*$)");
	std::regex ex2("(^dump$)|(^dump\\s*;.*$)");
	std::regex ex3("(^add$)|(^add\\s*;.*$)");
	std::regex ex4("(^sub$)|(^sub\\s*;.*$)");
	std::regex ex5("(^mul$)|(^mul\\s*;.*$)");
	std::regex ex6("(^div$)|(^div\\s*;.*$)");
	std::regex ex7("(^mod$)|(^mod\\s*;.*$)");
	std::regex ex8("(^print$)|(^print\\s*;.*$)");
	std::regex ex9("(^exit$)|(^exit\\s*;.*$)");

	std::regex ex10("(^push\\s(int32)\\(-?[[:digit:]]+\\)$)|(^push\\sint32\\(-?[[:digit:]]+\\s*;.*\\)$\\)");
	//std::regex ex11("(^assert\\s-?[[:digit:]]+$)|(^assert\\s-?[[:digit:]]+\\s*;.*$)");
	//std::regex ex12("(^push\\s-?[[:digit:]]+\\.[[:digit:]]++$)|(^push\\s-?[[:digit:]]+\\.[[:digit:]]+\\s*;.*$)");
	//std::regex ex13("(^assert\\s-?[[:digit:]]+\\.[[:digit:]]++$)|(^assert\\s-?[[:digit:]]+\\.[[:digit:]]+\\s*;.*$)");
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i] == "")
			continue;
		if (lines[i].length() > 2 && lines[i].at(0) == ';' && lines[i].at(1) != ';')
			continue;
		if (std::regex_match(lines[i], ex1) || std::regex_match(lines[i], ex2) || std::regex_match(lines[i], ex3) || std::regex_match(lines[i], ex4) || 
		std::regex_match(lines[i], ex5) || std::regex_match(lines[i], ex6) || std::regex_match(lines[i], ex7) || std::regex_match(lines[i], ex8) || 
		std::regex_match(lines[i], ex9) || std::regex_match(lines[i], ex10) /*|| std::regex_match(lines[i], ex11) || std::regex_match(lines[i], ex12) || 
		std::regex_match(lines[i], ex13)*/) {
			this->value.push_back(lines[i]);
			std::cout << lines[i] << std::endl;
		}
	}
	
	// for (int i = 0; i < this->value.size(); ++i) {
	// 	std::cout << this->value[i] << std::endl;
	// }
}