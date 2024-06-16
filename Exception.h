#pragma once

#include <cstdarg>
#include <exception>

#include "Node.h"

class Exception : public std::exception {
public:
	Exception(const char * fmt, ...);
	virtual ~Exception();
	virtual const char * what();

protected:
	Exception() = default;
	void va_format(va_list args, const char * fmt);
	char * error = NULL;
};

class ParserException : public Exception {
public:
	using Exception::Exception;
	ParserException(const char * fmt, ...);
};

class CircuitException : public Exception {
public:
	using Exception::Exception;
	CircuitException(const char * fmt, ...);
	Node * node = nullptr;
};

class NodeException : public CircuitException {
public:
	using CircuitException::CircuitException;
	NodeException(Node * node, const char * fmt, ...);
};

