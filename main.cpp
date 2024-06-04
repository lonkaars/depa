#include <iostream>
#include <exception>
#include <fstream>

#include "Parser.h"
#include "Circuit.h"

using std::cout;
using std::endl;
using std::fstream;
using std::exception;

int main(int argc, char** argv) {
  Parser main_parser;
  Circuit circuit;

  main_parser.setCircuit(circuit);

  fstream file{"circuits/full-adder.txt", file.out};

  try {
    main_parser << file;
  } catch (exception e) {
    cout << "Parser error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

  try {
    circuit.run();
  } catch (exception e) {
    cout << "Circuit error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

  cout << "Circuit output: " << circuit.getOutput() << endl;

	return EXIT_SUCCESS;
}

