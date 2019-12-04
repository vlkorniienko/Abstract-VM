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
    void push(const eOperandType operandType, const std::string value);

    std::string commandToString(::instructions type) const;
	std::string stringRepresentation(::eOperandType e) const;
    int getSize() const;

private:
    int size;
    std::vector<const IOperand*> stack;
};