#include "MyException.hpp"

MyException::MyException(std::string message):std::exception() {
    this->message = message;
}

std::string MyException::getMessage() {
    return this->message;
}