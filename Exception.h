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

class ParserException : public Exception { using Exception::Exception; };
class CircuitException : public Exception { using Exception::Exception; };
