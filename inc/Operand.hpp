#pragma once

#include "IOperand.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include <cmath>

class Operand : public IOperand {
public:
	Operand(std::string const & value, eOperandType type);
	Operand(Operand const & rhs);
	Operand & operator=(Operand const & rhs);
	~Operand();
	int					getPrecision() const override;
	eOperandType		getType() const override;
	IOperand const *	operator+(IOperand const & rhs) const override;
	IOperand const *	operator-(IOperand const & rhs) const override;
	IOperand const *	operator*(IOperand const & rhs) const override;
	IOperand const *	operator/(IOperand const & rhs) const override;
	IOperand const *	operator%(IOperand const & rhs) const override;
	std::string const & toString() const override;

private:
	std::string		value;
	eOperandType	type;
	Parser			parser;
};