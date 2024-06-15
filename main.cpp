#include <iostream>
#include <fstream>
#include <istream>

#include "Parser.h"
#include "Circuit.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istream;

istream * open_input(int argc, char** argv) {
	if (argc > 1) {
		ifstream * file = new ifstream(argv[1]);
		if (!file->is_open()) return nullptr;
		return file;
	}

	return &std::cin;
}

int main(int argc, char** argv) {
	istream * input = open_input(argc, argv);
	if (input == nullptr) {
		cout << "Could not open file" << endl;
		return EXIT_FAILURE;
	}

	Circuit circuit;
	Parser parser(circuit);

	try {
		*input >> parser;
	} catch (ParserException & e) {
		cout << "Parser error: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	try {
	  circuit.sim();
	} catch (CircuitException & e) {
	  cout << "Circuit error: " << e.what() << endl;
	  return EXIT_FAILURE;
	}

	cout << circuit.result();
	return EXIT_SUCCESS;
}

