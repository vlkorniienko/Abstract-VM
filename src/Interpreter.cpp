#include "Interpreter.hpp"

Interpreter::Interpreter() {}

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
		} else if (line[i].commands == add_i || line[i].commands == sub_i || line[i].commands == mul_i) {
			addSubMulOperations(line[i].commands);
		} else {
			divModOperations(line[i].commands);
		}
    }
}

void Interpreter::pushStack(const eOperandType operandType, const std::string value) {
    this->stack.push_back(Factory().createOperand(operandType, value));
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
}

void Interpreter::dumpStack() {
	try {
		if (this->stack.empty())
			throw DumpEmptyStackException();
		for (int i = this->stack.size(); i > 0; i--) {
			std::cout << stringRepresentation(this->stack[i - 1]->getType()) << "(" << this->stack[i - 1]->toString() << ")" << std::endl;
		}
	} catch (DumpEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::assertStack(const eOperandType operandType, const std::string value) {
	try {
		if (this->stack.empty())
			throw AssertEmptyStackException();
		if (operandType != this->stack.back()->getType() || value != this->stack.back()->toString()) {
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
		if (this->stack.back()->getType() != Int8)
			throw ValueIsNotInt8Exception();
		std::cout << "print front of stack:\n" << static_cast<char>(std::stoi(this->stack.back()->toString())) << std::endl; 
	} catch (PrintEmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	} catch (ValueIsNotInt8Exception &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::addSubMulOperations(instructions command) {
	try {
		if (this->stack.size() < 2)
			throw EmptyStackException();
		const IOperand* operand1 = stack.back();
		stack.pop_back();
		const IOperand* operand2 = stack.back();
		stack.pop_back();
		if (command == add_i) {
			const IOperand* result = *operand1 + *operand2;
			if (result == nullptr)
				throw NewOperandOverflowException();
			stack.push_back(result);
		} else if (command == sub_i) {
			const IOperand* result = *operand2 - *operand1;
			if (result == nullptr)
				throw NewOperandOverflowException();
			stack.push_back(result);
		} else if (command == mul_i) {
			const IOperand* result = *operand1 * *operand2;
			if (result == nullptr)
				throw NewOperandOverflowException();
			stack.push_back(result);
		}
	} catch (EmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	} catch (NewOperandOverflowException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}

void Interpreter::divModOperations(instructions command) {
	try {
		if (this->stack.size() < 2)
			throw EmptyStackException();
		const IOperand* operand1 = stack.back();
		if (std::stod(operand1->toString()) == 0)
			throw DivisionByZeroException();
		stack.pop_back();
		const IOperand* operand2 = stack.back();
		stack.pop_back();
		if (command == div_i) {
			const IOperand* result = *operand2 / *operand1;
			if (result == nullptr)
				throw NewOperandOverflowException();
			stack.push_back(result);
		} else if (command == mod_i) {
			const IOperand* result = *operand2 % *operand1;
			if (result == nullptr)
				throw NewOperandOverflowException();
			stack.push_back(result);
		}
	} catch (EmptyStackException &e) {
		std::cout << e.what() << std::endl;
		exit(0);
	} catch (DivisionByZeroException &e) {
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