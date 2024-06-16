#include "Node.h"
#include "NodeFactory.h"
#include "Net.h"
#include "Exception.h"

Node::Node(const char * type) {
	NodeFactory::assign(type, this);
}

void Node::addInput(Net * net) {
	net->attach(this);
	inputs.push_back(net);
}

void Node::setOutput(Net * net){
	if (this->output != nullptr)
		throw NodeException(this, "net already assigned");

	this->output = net;
}

void Node::sim() {
	size_t input_size = this->inputs.size();
	if (this->min_inputs >= 0 && input_size < min_inputs)
		throw NodeException(this, "too few inputs (expected >= %d, got %d)", min_inputs, input_size);
	if (this->max_inputs >= 0 && input_size > max_inputs)
		throw NodeException(this, "too many inputs (expected <= %d, got %d)", max_inputs, input_size);
	
	// output may be unconnected
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

