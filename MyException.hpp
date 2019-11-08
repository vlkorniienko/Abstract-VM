#pragma once

#include <exception>
#include <string>

class NoExitException : public std::exception {
    public:
      virtual const char *what() const throw() {
        return (" Error: there is no exit command[machine stop its work]");
	}
};

class RegexException : public std::regex_error {
    public:
      virtual const char *what() const throw() {
        return (" Error: error in regular expression");
	}
};