#include "Lexer.hpp"

Lexer::Lexer() { this->exit_check = false; }

bool Lexer::getExit() const {
	return this->exit_check;
}

std::vector<Line> Lexer::getLineVector() const {
	return this->lineVector;
}

void Lexer::RegularResult(const std::vector<std::string> & lines) {
	std::stringstream	errorMessage;
	Line				oneLine;
	int					counter;

	counter = 0;
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
		// reg expressions for complicated commands
		std::regex push_c("(^push\\s(int32|int16|int8|float|double)\\(.+\\)$)|(^push\\s(int32|int16|int8|float|double)\\(.+\\)\\s*;.*$)");
		std::regex assert_c("(^assert\\s(int32|int16|int8|float|double)\\(.+\\)$)|(^assert\\s(int32|int16|int8|float|double)\\(.+\\)\\s*;.*$)");
		
		for (long unsigned int i = 0; i < lines.size() && this->exit_check != true; i++)
		{
			oneLine.isSimpleCommand = true;
			if (lines[i].length() == 0 || lines[i] == ";") {
				counter++;
				continue;
			}
			else if (lines[i].length() >= 2 && lines[i].at(0) == ';') {
				counter++;
				continue;
			}
			else if (std::regex_match(lines[i], exit_c)) {
				oneLine.commands = exit_i;
				this->lineVector.push_back(oneLine);
				this->exit_check = true;
			} else if (std::regex_match(lines[i], pop_c)) {
				oneLine.commands = pop_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], dump_c)) {
				oneLine.commands = dump_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], add_c)) {
				oneLine.commands = add_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], sub_c)) {
				oneLine.commands = sub_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], mul_c)) {
				oneLine.commands = mul_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], div_c)) {
				oneLine.commands = div_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], mod_c)) {
				oneLine.commands = mod_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], print_c)) {
				oneLine.commands = print_i;
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], push_c)) {
				oneLine.isSimpleCommand = false;
				oneLine.commands = push_i;
				oneLine.value = lines[i];
				this->lineVector.push_back(oneLine);
			} else if (std::regex_match(lines[i], assert_c)) {
				oneLine.isSimpleCommand = false;
				oneLine.commands = assert_i;
				oneLine.value = lines[i];
				this->lineVector.push_back(oneLine);
			} else {
				std::cout << "Error: an unknown instruction is on line" << i + 1 << " [" << lines[i] << "]" << std::endl;
				counter++;
			}
		}
	} catch (RegexException& e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		if (getExit() == false) {
			throw NoExitException();
		}
	} catch (NoExitException& e) {
		std::cout << e.what() << std::endl;
		exit(-1);
	}

	findErrInValue(counter);
}

void	Lexer::findErrInValue(int counter) {
	std::regex push_dec("(^push\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)$)|(^push\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)\\s*;.*$)");
	std::regex push_fl("(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
	std::regex push_db("(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
	
	std::regex assert_dec("(^assert\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)$)|(^assert\\s(int32|int16|int8)\\(-?[[:digit:]]+\\)\\s*;.*$)");
	std::regex assert_fl("(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
	std::regex assert_db("(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");

	try {
		for (long unsigned int i = 0; i < this->lineVector.size(); i++) {
			if (!std::regex_match(this->lineVector[i].value, assert_dec) && !std::regex_match(this->lineVector[i].value, assert_fl) && !std::regex_match(this->lineVector[i].value, assert_db) && 
				!std::regex_match(this->lineVector[i].value, push_dec) && !std::regex_match(this->lineVector[i].value, push_fl) && !std::regex_match(this->lineVector[i].value, push_db)) {
					std::cout << "Error: value must be only digits [line " << i + 1 + counter<< "]" << std::endl;
					this->lineVector.erase(this->lineVector.begin() + i);
				}
		}
	} catch (RegexException& e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
