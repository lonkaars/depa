#include "Exception.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

Exception::~Exception() {
	if (error != NULL)
		free(error);
}

const char * Exception::what() {
	return error;
}

void Exception::va_format(va_list args, const char * fmt) {
	va_list args_copy;
	va_copy(args_copy, args);

	size_t sz = vsnprintf(NULL, 0, fmt, args_copy) + 1;
	if (error != NULL) free(error);
	error = (char *) malloc(sz);
	va_end(args_copy);

	vsnprintf(error, sz, fmt, args);
}

Exception::Exception(const char * fmt, ...) {
	va_list args;
	va_start(args, fmt);
	va_format(args, fmt);
	va_end(args);
}
CircuitException::CircuitException(const char * fmt, ...) {
	va_list args;
	va_start(args, fmt);
	va_format(args, fmt);
	va_end(args);
}
ParserException::ParserException(const char * fmt, ...) {
	va_list args;
	va_start(args, fmt);
	va_format(args, fmt);
	va_end(args);
}
