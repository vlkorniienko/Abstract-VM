#pragma once

#include "IOperand.hpp"

class Operand {
public:
	Operand(std::string value) { this->value = value; }
	~Operand();
	std::string value;
};