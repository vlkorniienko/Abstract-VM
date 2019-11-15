#pragma once

#include <string>

typedef enum { Int8, Int16, Int32, Float, Double,
} eOperandType;

typedef enum { pop_i, dump_i, add_i, sub_i, mul_i, div_i, mod_i, print_i, exit_i, push_i, assert_i,
} instructions;

std::string interpreter(::instructions type);
std::string interpreter2(::eOperandType e);

struct Line {
	eOperandType	operandType;
	std::string		value;
	instructions	commands;
	bool			isSimpleCommand;
};