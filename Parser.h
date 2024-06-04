#pragma once

#include <iostream>
#include <istream>

using std::istream;
using std::string;

class Parser {
public:
	void parse(string input) const;

private:
	istream & parse(const Parser & parser, istream & s) const;
	friend istream & operator << (const Parser & parser, istream & s);
	friend istream & operator >> (istream & s, const Parser & parser);
};

