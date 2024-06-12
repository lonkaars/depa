#include <iostream>

#include "Node.h"
#include "NodeFactory.h"
#include "Net.h"

#include "prut.h"

Node::Node(const char * type) {
	NodeFactory::assign(type, this);
}

void Node::addInput(Net * net) {
	net->attach(this);
	inputs.push_back(net);
}

void Node::setOutput(Net * net){
	this->output = net;
}

void Node::sim() {
	size_t input_size = this->inputs.size();
	if (this->min_inputs >= 0 && input_size < min_inputs)
		throw CircuitException("Too few inputs");
	if (this->max_inputs >= 0 && input_size > max_inputs)
		throw CircuitException("Too many inputs");

	SignalLevel new_out = this->level();

	if (new_out == UNDEFINED) return;
	if (this->output->getLevel() == new_out) return;

	this->output->setLevel(new_out);
}

void Node::update(){
	prutprint("updated");
	this->sim();
}

