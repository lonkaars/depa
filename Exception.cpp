#include "Exception.h"

#include <cstdarg>
#include <cstdio>

Exception::Exception(const char * fmt, ...) {
	va_list args;
	va_start(args, fmt);
	size_t sz = vsnprintf(NULL, 0, fmt, args) + 1;
	if (error != NULL) free(error);
	error = (char *) malloc(sz);
	vsnprintf(error, sz, fmt, args);
	va_end(args);
}

Exception::~Exception() {
	if (error != NULL)
		free(error);
}

const char * Exception::what() {
	return error;
}