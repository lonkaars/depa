#include <iostream>

#include "GateAnd.h"

using std::cout;
using std::endl;

GateAnd GateAnd::instance(GateAnd::type);

GateAnd::GateAnd(const char * type) : Node(type) {
	cout << __PRETTY_FUNCTION__ << endl;
}

// Concrete Nodes:
void GateAnd::compare() {
	SignalLevel new_out = HIGH;
// TODO fix segfault somewhere below
// for (int i = 0; i < this->inputs.size(); i++){
//    switch (this->inputs[i]->getLevel()){
//    case LOW:
//       new_out = LOW;
//       break;
//    case HIGH:
//       continue;
//       break;
//    case UNDEFINED:
//    default:
//       new_out = UNDEFINED;
//       exit;
//       break;
//    }
// }

// if (this->output->getLevel() == new_out){
//    /* do nothing */
// } else {
//    this->output->setLevel(new_out);
// }
}
