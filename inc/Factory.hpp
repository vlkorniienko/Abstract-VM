#pragma once

#include "Operand.hpp"
#include <string>
#include <vector>

class Factory {
public:
	Factory();
	~Factory();
	Operand const * createOperand(eOperandType type, std::string const & value) const;
	//IOperand (Factory::*ptrToMember[5])(eOperandType type);
	//IOperand const * (Factory::*ptrToMember)(std::string const & value) const;
	std::vector<Operand const *(Factory::*)(std::string const & value) const> factory;

private:
	Operand const * createInt8(std::string const & value) const;
	Operand const * createInt16(std::string const & value) const;
	Operand const * createInt32(std::string const & value) const;
	Operand const * createFloat(std::string const & value) const;
	Operand const * createDouble(std::string const & value) const;
};