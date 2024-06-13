#include <iostream>

#include "Node.h"
#include "NodeFactory.h"
#include "Net.h"
#include "Exception.h"

#include "prut.h"

Node::Node(const char * type) {
	NodeFactory::assign(type, this);
}

void Node::addInput(Net * net) {
	net->attach(this);
	inputs.push_back(net);
}

void Node::setOutput(Net * net){
	if (this->output == nullptr) {
		this->output = net;
	} else {
		throw CircuitException("Net already assigned");
	}
}

void Node::sim() {
	size_t input_size = this->inputs.size();
	if (this->min_inputs >= 0 && input_size < min_inputs)
		throw CircuitException("Too few inputs");
	if (this->max_inputs >= 0 && input_size > max_inputs)
		throw CircuitException("Too many inputs");
	
	// NodeOutput does not have an output itself
	if (this->output == nullptr) return;

	SignalLevel new_out = this->level();

	// don't propagate if undefined
	if (new_out == UNDEFINED) return;
	// don't propagate if unchanged
	if (this->output->getLevel() == new_out) return;

	this->output->setLevel(new_out);
}

void Node::update(){
	this->sim();
}

