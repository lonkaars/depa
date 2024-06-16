#pragma once

#include <iostream>
#include <istream>


#include "Circuit.h"

using std::istream;
using std::string;

class Parser {
public:
	Parser() = default;
	Parser(Circuit & circuit);
	virtual ~Parser() = default;

	//! parse from std::string
	void parse(string input);
	//! parse from std::istream
	void parse(istream & input);

	/**
	 * \brief preprocess (filter) line of input
	 *
	 * normalize whitespace and remove comments
	 */
	static size_t filter(char * input);

	//! inject Circuit instance
	void set_circuit(Circuit & circuit);

private:
	friend istream & operator << (Parser & parser, istream & s);
	friend istream & operator >> (istream & s, Parser & parser);

	Circuit * circuit;
};

