#include "NodeInput.h"
#include "prut.h"


NodeInput NodeInput::instance(NodeInput::type);
NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);

NodeInput::NodeInput(const NodeInput * prototype) : Node() { }

NodeInput * NodeInput::clone() const {
	return new NodeInput(this);
}

SignalLevel NodeInput::level() {
	prutprint("BaseInput");
	return UNDEFINED;
}
SignalLevel NodeInputLow::level() {
	prutprint("LOW");
	return LOW;
}
SignalLevel NodeInputHigh::level() {
	prutprint("HIGH");
	return HIGH;
}

