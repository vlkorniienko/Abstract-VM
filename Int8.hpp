#pragma once

#include "IOperand.hpp"
#include <string>

class Int8 : public IOperand {
public:

    virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;

	virtual IOperand const * operator+(IOperand const & rhs) const;
	virtual IOperand const * operator-(IOperand const & rhs) const;
	virtual IOperand const * operator*(IOperand const & rhs) const;
	virtual IOperand const * operator/(IOperand const & rhs) const;
	virtual IOperand const * operator%(IOperand const & rhs) const;
    
    virtual std::string const & toString(void) const;

private:
    eOperandType operandType;
	char value;
};