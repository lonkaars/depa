#pragma once

#include <cstdarg>
#include <exception>

#include "Node.h"

class Exception : public std::exception {
public:
	//! create an exception using printf-syntax
	Exception(const char * fmt, ...);
	virtual ~Exception();
	//! get the formatted string
	virtual const char * what();

protected:
	Exception() = default;
	//! internal variadic argument format handling
	void va_format(va_list args, const char * fmt);
	//! pointer to string returned by \p what()
	char * error = NULL;
};

class ParserException : public Exception {
	using Exception::Exception;

public:
	//! create an exception related to file format parsing
	ParserException(const char * fmt, ...);
};

class CircuitException : public Exception {
	using Exception::Exception;

public:
	//! create an exception related to the Circuit
	CircuitException(const char * fmt, ...);
	Node * node = nullptr;
};

class NodeException : public CircuitException {
	using CircuitException::CircuitException;

public:
	//! create an exception related to a specific node in a Circuit
	NodeException(Node * node, const char * fmt, ...);
};

