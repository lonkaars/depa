#include "NodeOutput.h"
#include "Exception.h"

NodeOutput NodeOutput::instance(NodeOutput::type);

NodeOutput::NodeOutput(const char * type) : Node(type) { init(); }

void NodeOutput::init() {
	this->min_inputs = 1;
	this->max_inputs = 1;
}

void NodeOutput::sim() {
	Node::sim();
	this->input = this->inputs[0]->getLevel();
}

NodeOutput::NodeOutput(const NodeOutput * prototype) : Node() { init(); }

NodeOutput * NodeOutput::clone() const {
	return new NodeOutput(this);
}

void NodeOutput::setOutput(Net *) {
	throw CircuitException("NodeOutput cannot have an output");
}

SignalLevel NodeOutput::level() {
	return this->input;
}

