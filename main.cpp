#include <iostream>
#include <fstream>

#include "Parser.h"
#include "Circuit.h"

using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char** argv) {
	Parser main_parser;
	Circuit circuit;

	main_parser.set_circuit(circuit);

	ifstream file("circuits/and-test.txt");

	try {
		file >> main_parser;
		// main_parser << file;
	} catch (ParserException & e) {
		cout << "Parser error: " << e.what() << endl;
		return EXIT_FAILURE;
	} catch (CircuitException & e) {
	  cout << "Circuit error: " << e.what() << endl;
	  return EXIT_FAILURE;
	}

	try {
	  circuit.sim();
	} catch (CircuitException & e) {
	  cout << "Circuit error: " << e.what() << endl;
	  return EXIT_FAILURE;
	}

	// cout << "Circuit output: " << circuit.getOutput() << endl;

	return EXIT_SUCCESS;
}

