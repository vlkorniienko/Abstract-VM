#include "Interpreter.hpp"

Interpreter::Interpreter() {
    this->size = 0;
}

Interpreter::~Interpreter() {}

void Interpreter::VM(std::vector<Line> &line) {
    for (long unsigned int i = 0; i < line.size(); i++) {
        if (line[i].commands == push_i) {
            pushStack(line[i].operandType, line[i].value);
		} else if (line[i].commands == pop_i) {
			popStack();
		} else if (line[i].commands == dump_i) {
			dumpStack();
		} else if (line[i].commands == assert_i) {
			assertStack(line[i].operandType, line[i].value);
		} else if (line[i].commands == print_i) {
			printStack();
		} else if (line[i].commands == exit_i) {
			break;
		} else if (line[i].commands == add_i) {
			addStack();
		}
    }

	for (long unsigned int i = 0; i < this->stack.size(); i++) {
		std::cout << stringRepresentation(this->stack[i]->getType()) << " (" << this->stack[i]->toString() << ")" << std::endl;
	}
}

void Interpreter::pushStack(const eOperandType operandType, const std::string value) {
    this->stack.push_back(Factory().createOperand(operandType, value));
    this->size++;
}

void Interpreter::popStack() {
	try {
		if (this->stack.empty())
			throw PopEmptyStackException();
	} catch (PopEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
	this->stack.pop_back();
	size--;
}

void Interpreter::dumpStack() {
	try {
		if (this->stack.empty())
			throw DumpEmptyStackException();
	} catch (DumpEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::assertStack(const eOperandType operandType, const std::string value) {
	try {
		if (this->stack.empty())
			throw AssertEmptyStackException();
		if (operandType != this->stack.front()->getType() || value != this->stack.front()->toString()) {
			throw AssertException();
		}
	} catch (AssertEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	} catch (AssertException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::printStack() {
	try {
		if (this->stack.empty())
			throw PrintEmptyStackException();
		if (this->stack.front()->getType() != Int8)
			throw ValueIsNotInt8Exception();
		std::cout << "print front of stack:\n" << static_cast<char>(std::stoi(this->stack.front()->toString())) << std::endl; 
	} catch (PrintEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	} catch (ValueIsNotInt8Exception &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::addStack() {
	try {
		if (this->size < 2)
			throw EmptyStackException();
		const IOperand* operand1 = stack.back();
		stack.pop_back();
		const IOperand* operand2 = stack.back();
		stack.pop_back();
		const IOperand *result = *operand1 + *operand2;
		stack.push_back(result);
	} catch (EmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
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