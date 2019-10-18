#include "Int8.hpp"

const std::string & Int8::toString() const {
    return "Int8";
}

eOperandType Int8::getType() const {
    return this->operandType;
}