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
	g->addInput(&n);
	g->addInput(&n1);
	g->setOutput(&o);

	// o.setLevel(UNDEFINED);
	n.setLevel(LOW);
	n1.setLevel(LOW);
	int level = 22;
	level = o.getLevel();
	printf("hello world! %d\n", level);
	return 0;
}

/*
int main(int argc, char** argv) {
	Parser main_parser;
	Circuit circuit;

	main_parser.set_circuit(circuit);

	ifstream file("circuits/full-adder.txt");

	try {
		file >> main_parser;
		// main_parser << file;
	} catch (ParserException & e) {
		cout << "Parser error: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	// try {
	//   circuit.run();
	// } catch (exception& e) {
	//   cout << "Circuit error: " << e.what() << endl;
	//   return EXIT_FAILURE;
	// }

	// cout << "Circuit output: " << circuit.getOutput() << endl;

	return EXIT_SUCCESS;
}

*/