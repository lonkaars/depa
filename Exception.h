#pragma once

#include <exception>

class Exception : public std::exception {
public:
	Exception(const char * fmt, ...);
	virtual ~Exception();
	virtual const char * what();

private:
	char * error = NULL;
};

class ParserException : public Exception {
public:
	ParserException(const char * fmt, ...) : Exception(fmt) {}
};

class CircuitException : public Exception {
public:
	CircuitException(const char * fmt, ...) : Exception(fmt) {}
};
