#pragma once

#include "IOperand.hpp"

class Operand : public IOperand {
public:
	Operand(eOperandType type, std::string value);
	Operand(Operand const & src);
	Operand & operator=(Operand const & rhs);
	~Operand();
	int					getPrecision() const;
	eOperandType		getType() const;
	IOperand const *	operator+(IOperand const & rhs) const;
	IOperand const *	operator-(IOperand const & rhs) const;
	IOperand const *	operator*(IOperand const & rhs) const;
	IOperand const *	operator/(IOperand const & rhs) const;
	IOperand const *	operator%(IOperand const & rhs) const;
	std::string const & toString(void) const;

private:
	std::string		value;
	eOperandType	type;
};