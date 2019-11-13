#include "Parser.hpp"

void Parser::parseOperands(std::vector<Line> &line) {
	try {
	
		std::regex push_int8("(^push\\sint8\\(-?[[:digit:]]+\\)$)|(^push\\sint8\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_int16("(^push\\sint16\\(-?[[:digit:]]+\\)$)|(^push\\sint16\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_int32("(^push\\sint32\\(-?[[:digit:]]+\\)$)|(^push\\sint32\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_fl("(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		std::regex push_db("(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^push\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");

		std::regex assert_int8("(^assert\\sint8\\(-?[[:digit:]]+\\)$)|(^assert\\sint8\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_int16("(^assert\\sint16\\(-?[[:digit:]]+\\)$)|(^assert\\sint16\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_int32("(^assert\\sint32\\(-?[[:digit:]]+\\)$)|(^assert\\sint32\\(-?[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_fl("(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sfloat\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");
		std::regex assert_db("(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)$)|(^assert\\sdouble\\(-?[[:digit:]]+\\.[[:digit:]]+\\)\\s*;.*$)");

		for(unsigned long int i = 0; i < line.size(); i++) {
			if (!line[i].isSimpleCommand) {
				if (std::regex_match(line[i].value, push_int8) || std::regex_match(line[i].value, assert_int8)) {
					line[i].operandType = Int8;
				} else if (std::regex_match(line[i].value, push_int16) || std::regex_match(line[i].value, assert_int16)) {
					line[i].operandType = Int16;
				} else if (std::regex_match(line[i].value, push_int32) || std::regex_match(line[i].value, assert_int32)) {
					line[i].operandType = Int32;
				} else if (std::regex_match(line[i].value, push_fl) || std::regex_match(line[i].value, assert_fl)) {
					line[i].operandType = Float;
				} else if (std::regex_match(line[i].value, push_db) || std::regex_match(line[i].value, assert_db)) {
					line[i].operandType = Double;
				}
			}
		}
	} catch(RegexException& e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Parser::parseLines(std::vector<Line> &line) {
	parseOperands(line);
	extractValue(line);

	for (long unsigned int i = 0; i < line.size(); i++) {
		std::cout << interpreter(line[i].commands) << " ";
		if (!line[i].isSimpleCommand) {
			std::cout << interpreter2(line[i].operandType) << "(" << line[i].value << ")";
		}
		std::cout << "\n";
	}
	
}

void Parser::extractValue(std::vector<Line> &line) const {
	for (long unsigned int counter = 0; counter < line.size(); counter++) {
		if (!line[counter].isSimpleCommand) {
			long unsigned int j = 0, i = 0;
			long unsigned int temp;
			for ( ; i < line[counter].value.length(); i++) { 
				if (line[counter].value[i] == '(') {
					break;
				}
			}
			temp = i + 1;
			for ( ; temp < line[counter].value.length(); temp++) {
				if (line[counter].value[temp] == ')') { 
					break ;
				}
				j++;
			}
			line[counter].value = line[counter].value.substr(i + 1, j);
		}
	}
}






// typedef enum { pop_i, dump_i, add_i, sub_i, mul_i, div_i, mod_i, print_i, exit_i, push_i, assert_i,
// } instructions;