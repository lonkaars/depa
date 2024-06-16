#include "NodeInput.h"
#include "Exception.h"

NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);

NodeInput::NodeInput() : Node() {
	this->min_inputs = 0;
	this->max_inputs = 0;
}
void NodeInput::addInput(Net *) {
	throw NodeException(this, "NodeInput cannot have inputs");
}

NodeInputLow * NodeInputLow::clone() const {
	return new NodeInputLow(this);
}
SignalLevel NodeInputLow::level() { return LOW; }

NodeInputHigh * NodeInputHigh::clone() const {
	return new NodeInputHigh(this);
}
SignalLevel NodeInputHigh::level() { return HIGH; }

