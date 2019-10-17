#pragma once
#include "IOperand.hpp"
#include <string>

class Int8 : public IOperand {

    virtual std::string const & toString(void) const;
};