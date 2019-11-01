#include "Lexer.hpp"

Lexer::Lexer() { this->exit_check = false; }

void Lexer::RegularResult(const std::vector<std::string> & lines) {
	std::stringstream errorMessage;

	try {
		// standart commands
		std::regex pop_c("(^pop$)|(^pop\\s*;.*$)");
		std::regex dump_c("(^dump$)|(^dump\\s*;.*$)");
		std::regex add_c("(^add$)|(^add\\s*;.*$)");
		std::regex sub_c("(^sub$)|(^sub\\s*;.*$)");
		std::regex mul_c("(^mul$)|(^mul\\s*;.*$)");
		std::regex div_c("(^div$)|(^div\\s*;.*$)");
		std::regex mod_c("(^mod$)|(^mod\\s*;.*$)");
		std::regex print_c("(^print$)|(^print\\s*;.*$)");
		std::regex exit_c("(^exit$)|(^exit\\s*;.*$)");
		// reg expressions for push command
		std::regex push_dec("(^push\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)$)|(^push\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_fl("(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_db("(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		// reg expressions for assert command
		std::regex assert_dec("(^assert\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)$)|(^assert\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_fl("(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_db("(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		for (long unsigned int i = 0; i < lines.size(); i++)
		{
			if (lines[i].length() == 0 || lines[i] == ";")
				continue;
			else if (lines[i].length() > 2 && lines[i].at(0) == ';' && lines[i].at(1) != ';')
				continue;
			else if (std::regex_match(lines[i], exit_c)) {
				this->value.push_back(lines[i]);
				this->exit_check = true;
			}
			else if (std::regex_match(lines[i], pop_c) || std::regex_match(lines[i], dump_c) || std::regex_match(lines[i], add_c) || std::regex_match(lines[i], sub_c) || 
				std::regex_match(lines[i], mul_c) || std::regex_match(lines[i], div_c) || std::regex_match(lines[i], mod_c) || std::regex_match(lines[i], print_c) || 
				std::regex_match(lines[i], push_dec) || std::regex_match(lines[i], assert_dec) || std::regex_match(lines[i], push_fl) || std::regex_match(lines[i], push_db) ||
				std::regex_match(lines[i], assert_fl) || std::regex_match(lines[i], assert_db)) {
					this->value.push_back(lines[i]);
			}
			else {
				std::cout << "An unknown instruction is on line" << i + 1 << " [" << lines[i] << "]\n" << "Machine continue working" << std::endl;	
			}
		}
	} catch (std::regex_error& e) {
		std::cout << "regex_error caught: " << e.what() << '\n';
	} catch (std::exception& e) {
    	std::cout << e.what() << std::endl;
	}
	try {
		if (this->exit_check == false) {
			throw MyException("Error: there is no exit command[machine stop its work]");
		}
	} catch (MyException& e) {
		std::cout << e.getMessage() << std::endl;
		exit(-1);
	}
}
