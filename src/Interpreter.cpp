#include "Interpreter.hpp"

Interpreter::Interpreter() {
    this->size = 0;
}

Interpreter::~Interpreter() {}

void Interpreter::VM(std::vector<Line> &line) {
    for (long unsigned int i = 0; i < line.size(); i++) {
        if (line[i].commands == ::push_i)
            push(line[i].operandType, line[i].value);
    }

}

void Interpreter::push(const eOperandType operandType, const std::string value) {
    this->stack.push_back(Factory().createOperand(operandType, value));
    this->size++;
}


std::string Interpreter::commandToString(::instructions type) const {
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

std::string Interpreter::stringRepresentation(::eOperandType e) const {
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