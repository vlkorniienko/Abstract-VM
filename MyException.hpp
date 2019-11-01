#pragma once

#include <exception>
#include <string>

class MyException : public std::exception {
    public:
        MyException(std::string message);
        ~MyException() = default;
        std::string getMessage();
    private:
    std::string message;
};