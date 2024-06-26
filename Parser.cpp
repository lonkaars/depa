#include <cstring>
#include <sstream>

#include "Parser.h"
#include "Exception.h"

using std::getline;

size_t Parser::filter(char * input) {
	size_t
		len = strlen(input),
		offset = 0,
		i = 0;

	while (i < len) {
		if(input[i] == '#') {
			offset += len - i;
			break;
		}

		size_t skip = strspn(input + i, " \t\n");
		if (skip > 0) {
			offset += skip;
			i += skip;
			continue;
		}

		input[i - offset] = input[i];
		i++;
	}

	input[len - offset] = '\0';
	return len - offset;
}

void Parser::set_circuit(Circuit & circuit) {
	this->circuit = &circuit;
}

void Parser::parse(istream & input) {
	unsigned linenum = 0;
	string line_str;
	while (getline(input, line_str)) {
		linenum++;
		char* line = line_str.data();
		size_t len = Parser::filter(line);

		if (len == 0) continue; // ignore empty lines

		char* label = strtok(line, ":");
		if (label == NULL) throw ParserException("syntax error on line %u", linenum);

		char* content = strtok(NULL, ";");
		if (content == NULL) throw ParserException("syntax error on line %u", linenum);

		vector<string> nodes;
		while ((content = strtok(content, ",")) != NULL) {
			nodes.push_back(content);
			content = NULL;
		}
		
		if (circuit == nullptr) throw ParserException("circuit is not initialized!");
	
		try {
			circuit->create(label, nodes);
		} catch(CircuitException & c) {
			throw ParserException("line %u: %s", linenum, c.what());
		}
	}
}

istream & operator >> (istream & s, Parser & parser) {
	parser.parse(s);
	return s;
}

istream & operator << (Parser & parser, istream & s) {
	parser.parse(s);
	return s;
}

void Parser::parse(string input) {
	std::istringstream s(input);
	parse(s);
}

Parser::Parser(Circuit & circuit) {
	set_circuit(circuit);
}

