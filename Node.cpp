#include "Node.h"

#include <iostream>

Node::Node(){}
Node::~Node(){}
void Node::addInput(Net* net){
	net->attach(this);
}
void Node::setOutput(Net* net){
	this->output = net;
}

void Node::update(){
	std::cout << "updated" << std::endl;
	this->compare();
}

/*/ Concrete Nodes: /*/

void GateAnd::compare(){
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
