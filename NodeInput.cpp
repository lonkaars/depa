#include "NodeInput.h"

NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);

NodeInput::NodeInput() {
	this->min_inputs = -1;
	this->max_inputs = 0;
}

NodeInputLow * NodeInputLow::clone() const {
	return new NodeInputLow(this);
}
SignalLevel NodeInputLow::level() { return LOW; }

NodeInputHigh * NodeInputHigh::clone() const {
	return new NodeInputHigh(this);
}
SignalLevel NodeInputHigh::level() { return HIGH; }

