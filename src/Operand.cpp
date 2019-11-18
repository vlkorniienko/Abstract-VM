#include "Operand.hpp"

Operand::Operand(eOperandType type, std::string value) {
	this->type = type;
	this->value = value;
}

eOperandType Operand::getType() const {
	return this->type;
}

std::string const & Operand::toString(void) const {
	return this->value;
}