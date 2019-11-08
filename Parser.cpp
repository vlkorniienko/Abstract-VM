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

        for(long int i = 0; i < line.size(); i++) {
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
    } catch(std::exception& e) {
        
    }
}

void Parser::parseLines(std::vector<Line> &line) {
	parseLines(line);
}