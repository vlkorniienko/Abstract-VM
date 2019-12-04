#pragma once

#include "Operand.hpp"
#include "IOperand.hpp"
#include <string>
#include <vector>


class Factory {
public:
	Factory();
	~Factory();
	IOperand const * createOperand(eOperandType type, std::string const & value) const;
	std::vector<IOperand const *(Factory::*)(std::string const & value) const> factory;

private:
	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;
};