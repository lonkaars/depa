#pragma once

#include <iostream>
#include <istream>
#include <exception>
#include <vector>

using std::istream;
using std::string;
using std::vector;

class ParserException : public std::exception {
public:
	ParserException(const char * fmt, ...);
	~ParserException();
	const char * what();

private:
	char * error = NULL;
};

class Parser {
public:
	void parse(string input) const;
	void parse(istream & input) const;

	/**
	 * \brief preprocess (filter) line of input
	 *
	 * normalize whitespace and remove comments
	 */
	static size_t filter(char * input);

	void handle_line(string label, vector<string> nodes) const;

private:
	friend istream & operator << (const Parser & parser, istream & s);
	friend istream & operator >> (istream & s, const Parser & parser);
};

