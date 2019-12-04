#pragma once

#include <exception>
#include <string>
#include <regex>

class NoExitException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: there is no exit command[machine stop its work]");
	}
};

class RegexException : public std::regex_error {
	public:
		virtual const char *what() const throw() {
			return ("Error: error in regular expression");
	}
};

class TooManyArguments : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: usage ./avm [filename] ");
	}
};

class UnderflowException : std::underflow_error {

public:
	UnderflowException(const std::string &s) : underflow_error(s), exc(s) {}

	virtual const char *what() const throw() override {
		return exc.c_str();
	}

private:
	std::string exc;
};

class OverflowException : std::overflow_error {

public:
	OverflowException(const std::string &s) : overflow_error(s), exc(s) {}

	virtual const char *what() const throw() override {
		return exc.c_str();
	}

private:
	std::string exc;
};

class PopEmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: pop empty stack exception");
	}
};

class DumpEmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: dump empty stack exception");
	}
};

class AssertEmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: assert empty stack exception");
	}
};


class AssertException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: value or type are not equal");
	}
};

class PrintEmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: print empty stack exception");
	}
};

class ValueIsNotInt8Exception : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: value at front of stack is not int8");
	}
};

class EmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Error: empty stack exception");
	}
};