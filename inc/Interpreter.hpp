#pragma once

#include "Line.hpp"
#include "MyException.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"

#include <vector>

class Interpreter {
public:
    Interpreter();
    ~Interpreter();
    void VM(std::vector<Line> &line);
    void pushStack(const eOperandType operandType, const std::string value);
    void popStack();
    void dumpStack();
    void assertStack(const eOperandType operandType, const std::string value);
    void printStack();
    void addStack();

    std::string commandToString(::instructions type) const;
	std::string stringRepresentation(::eOperandType e) const;
    int getSize() const;

private:
    int size;
    std::vector<const IOperand*> stack;
};