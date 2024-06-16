#include "NodeOutput.h"
#include "Exception.h"

NodeOutput NodeOutput::instance(NodeOutput::type);

void NodeOutput::sim() {
	Node::sim();
	this->input = this->inputs[0]->getLevel();
}

NodeOutput::NodeOutput(const NodeOutput * prototype) : Node() {
	this->min_inputs = 1;
	this->max_inputs = 1;
}

NodeOutput * NodeOutput::clone() const {
	return new NodeOutput(this);
}

void NodeOutput::setOutput(Net *) {
	throw NodeException(this, "NodeOutput cannot have an output");
}

SignalLevel NodeOutput::level() {
	return this->input;
}

