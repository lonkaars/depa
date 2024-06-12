#include "NodeInput.h"

#include <iostream>

NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);

NodeInput::NodeInput(const char * type) : Node(type) { };

void NodeInput::sim() {
	if (this->output == nullptr) return;
	// std::cout << this->level << " bar\n";
	this->output->setLevel(this->input);
}

NodeInput::NodeInput(const NodeInput * prototype) : Node() { }

NodeInput * NodeInput::clone() const {
	return new NodeInput(this);
}

SignalLevel NodeInput::level() {
	return UNDEFINED;
};

// NodeInputLow::NodeInputLow(const NodeInputLow * prototype) : NodeInput() { }

// // INPUT_HIGH
// NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);
// NodeInputHigh::NodeInputHigh(const char * type) : NodeInput(type) { }
// NodeInputHigh::NodeInputHigh(const NodeInputHigh * prototype) : NodeInput() { }
