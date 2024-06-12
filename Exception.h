#pragma once

#include <cstdarg>
#include <exception>

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
	ParserException(const char * fmt, ...);
};

class CircuitException : public Exception {
public:
	CircuitException(const char * fmt, ...);
};

