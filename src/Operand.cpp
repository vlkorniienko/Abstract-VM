#include "Operand.hpp"

Operand::Operand(std::string const & value, eOperandType type) {
	this->type = type;
	this->value = value;
}

Operand::Operand(Operand const & rhs) {
	*this = rhs;
}

eOperandType Operand::getType() const {
	return this->type;
}

std::string const & Operand::toString() const {
	return this->value;
}

int	Operand::getPrecision() const {
	return static_cast<int>(this->type);
}

Operand::~Operand() {}

Operand & Operand::operator=(Operand const & rhs) {
	if (this != &rhs) {
		this->value = rhs.value;
		this->type = rhs.type;
	}
	return *this;
}

IOperand const * Operand::operator+(IOperand const & rhs) const {
	eOperandType newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

	if (newType <= 2) {
		if (Parser().validateSize(std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString())));
		} else {
			return nullptr;
		}
	} else {
		if (Parser().validateSize(std::to_string(std::stod(this->toString()) + std::stod(rhs.toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stod(this->toString()) + std::stod(rhs.toString())));
		} else {
			return nullptr;
		}
	}
}

IOperand const * Operand::operator-(IOperand const & rhs) const {
	eOperandType newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

	if (newType <= 2) {
		if (Parser().validateSize(std::to_string(std::stoi(rhs.toString()) - std::stoi(this->toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stoi(rhs.toString()) - std::stoi(this->toString())));
		} else {
			return nullptr;
		}
	} else {
		if (Parser().validateSize(std::to_string(std::stod(rhs.toString()) - std::stod(this->toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stod(rhs.toString()) - std::stod(this->toString())));
		} else {
			return nullptr;
		}
	}
}

IOperand const * Operand::operator*(IOperand const & rhs) const {
	eOperandType newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

	if (newType <= 2) {
		if (Parser().validateSize(std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString())));
		} else {
			return nullptr;
		}
	} else {
		if (Parser().validateSize(std::to_string(std::stod(this->toString()) * std::stod(rhs.toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stod(this->toString()) * std::stod(rhs.toString())));
		} else {
			return nullptr;
		}
	}
}

IOperand const * Operand::operator/(IOperand const & rhs) const {
	eOperandType newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

	if (newType <= 2) {
		if (Parser().validateSize(std::to_string(std::stoi(rhs.toString()) / std::stoi(this->toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stoi(rhs.toString()) / std::stoi(this->toString())));
		} else {
			return nullptr;
		}
	} else {
		if (Parser().validateSize(std::to_string(std::stod(rhs.toString()) / std::stod(this->toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stod(rhs.toString()) / std::stod(this->toString())));
		} else {
			return nullptr;
		}
	}
}

IOperand const * Operand::operator%(IOperand const & rhs) const {
	eOperandType newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));

	if (newType <= 2) {
		if (Parser().validateSize(std::to_string(std::stoi(rhs.toString()) % std::stoi(this->toString())), newType)) {
			return Factory().createOperand(newType, std::to_string(std::stoi(rhs.toString()) % std::stoi(this->toString())));
		} else {
			return nullptr;
		}
	} else {
		if (Parser().validateSize(std::to_string(fmod(std::stod(rhs.toString()), std::stod(this->toString()))), newType)) {
			return Factory().createOperand(newType, std::to_string(fmod(std::stod(rhs.toString()), std::stod(this->toString()))));
		} else {
			return nullptr;
		}
	}
}