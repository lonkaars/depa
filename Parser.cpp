#include "Parser.h"

void Parser::parse(string input) const {
	std::cout << input << std::endl;
}

istream & Parser::parse(const Parser & parser, istream & s) const {
	string temp(std::istreambuf_iterator<char>(s), {});
	parse(temp);
	return s;
}

istream & operator >> (istream & s, const Parser & parser) {
	return parser.parse(parser, s);
}

istream & operator << (const Parser & parser, istream & s) {
	return parser.parse(parser, s);
}

