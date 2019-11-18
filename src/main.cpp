#include <vector>
#include <string>
#include "Lexer.hpp"
#include "Reader.hpp"
#include "Parser.hpp"
#include "Line.hpp"

int		main(int argc, char **argv)
{
	Reader 	reader;
	Lexer 	lexer;
	Parser 	parser;

	try {
		if (argc == 2)
			reader.readFromFile(argv[1]);
		else if (argc == 1)
			reader.readFromStdin();
		else {
			throw TooManyArguments();
		}
	} catch(TooManyArguments &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	lexer.RegularResult(reader.getCommands());
	std::vector<Line> lines = lexer.getLineVector();
	parser.parseLines(lines);
	
	return (0);
}

std::string interpreter(::instructions type) {
	if (type == pop_i) {
		return "pop";
	} else if (type == dump_i) {
		return "dump";
	} else if (type == add_i) {
		return "add";
	} else if (type == sub_i) {
		return "sub";
	} else if (type == mul_i) {
		return "mul";
	} else if (type == div_i) {
		return "div";
	} else if (type == mod_i) {
		return "mod";
	} else if (type == print_i) {
		return "print";
	} else if (type == exit_i) {
		return "exit";
	} else if (type == push_i) {
		return "push";
	} else {
		return "assert";
	}
}

std::string stringRepresentation(::eOperandType e) {
	if (e == Int8) {
		return "int8";
	} else if (e == Int16) {
		return "int16";
	} else if (e == Int32) {
		return "int32";
	} else if (e == Float) {
		return "float";
	} else {
		return "double";
	}
}

