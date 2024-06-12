#pragma once

#include <iostream>
#include <istream>
#include <exception>

#include "Circuit.h"

using std::istream;
using std::string;

class ParserException : public std::exception {
public:
	ParserException(const char * fmt, ...);
	virtual ~ParserException();
	virtual const char * what();

private:
	char * error = NULL;
};

class Parser {
public:
	Parser() = default;
	virtual ~Parser() = default;

	void parse(string input);
	void parse(istream & input);

	/**
	 * \brief preprocess (filter) line of input
	 *
	 * normalize whitespace and remove comments
	 */
	static size_t filter(char * input);

	void set_circuit(Circuit & circuit);

private:
	friend istream & operator << (Parser & parser, istream & s);
	friend istream & operator >> (istream & s, Parser & parser);

	Circuit * circuit;
};

