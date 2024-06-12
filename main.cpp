#include <iostream>
#include <fstream>

#include "Parser.h"
#include "Circuit.h"

using std::cout;
using std::endl;
using std::ifstream;

#include "Node.h"
#include "GateAnd.h"

int main() {
	// Observer ob();
	Net n, n1, o;
	Node *g = new GateAnd;
	try {
		g->addInput(&n);
		g->addInput(&n1);
		g->setOutput(&o);

		// o.setLevel(UNDEFINED);
		n.setLevel(HIGH);
		n1.setLevel(HIGH);
		int level = 22;
		level = o.getLevel();
		printf("hello world! %d\n", level);
	} catch(Exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}

/*
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

*/