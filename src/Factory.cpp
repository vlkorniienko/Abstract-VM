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

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
	IOperand const * (Factory::*ptrToMember)(std::string const & value) const = NULL;
	ptrToMember = this->factory.at(type);

	return (*this.*ptrToMember)(value);
}

IOperand const * Factory::createInt8(std::string const & value) const {
	return new IOperand(value, Int8, stringRepresentation(Int8));
}

IOperand const * Factory::createInt16(std::string const & value) const {
	return new IOperand(value, Int16, stringRepresentation(Int16));
}

IOperand const * Factory::createInt32(std::string const & value) const {
	return new IOperand(value, Int32, stringRepresentation(Int32));
}

IOperand const * Factory::createFloat(std::string const & value) const {
	return new IOperand(value, Float, stringRepresentation(Float));
}

IOperand const * Factory::createDouble(std::string const & value) const {
	return new IOperand(value, Double, stringRepresentation(Double));
}