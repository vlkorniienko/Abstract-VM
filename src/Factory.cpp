#include "Factory.hpp"
#include "Operand.hpp"

Factory::Factory() {
	factory.push_back(&Factory::createInt8);
	factory.push_back(&Factory::createInt16);
	factory.push_back(&Factory::createInt32);
	factory.push_back(&Factory::createFloat);
	factory.push_back(&Factory::createDouble);
}

Factory::~Factory() { }

Operand const * Factory::createOperand(eOperandType type, std::string const & value) const {
	Operand const * (Factory::*ptrToMember)(std::string const & value) const = NULL;
	ptrToMember = this->factory.at(type);

	return (*this.*ptrToMember)(value);
}

Operand const * Factory::createInt8(std::string const & value) const {
	return new Operand(value);
}

Operand const * Factory::createInt16(std::string const & value) const {
	return new Operand(value);
}

Operand const * Factory::createInt32(std::string const & value) const {
	return new Operand(value);
}

Operand const * Factory::createFloat(std::string const & value) const {
	return new Operand(value);
}

Operand const * Factory::createDouble(std::string const & value) const {
	return new Operand(value);
}