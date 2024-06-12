#include "NodeInput.h"
#include "prut.h"

#include <iostream>

NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);

NodeInput::NodeInput(const NodeInput * prototype) : Node() { }

NodeInput * NodeInput::clone() const {
	return new NodeInput(this);
}

SignalLevel NodeInput::level() {
	prutprint("");
	return UNDEFINED;
}
SignalLevel NodeInputLow::level() {
	prutprint("");
	return LOW;
}
SignalLevel NodeInputHigh::level() {
	prutprint("");
	return HIGH;
}

