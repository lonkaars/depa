#include "NodeInput.h"

NodeInput::NodeInput(const char * type) : Node(type) { }

void NodeInput::compare() {
   if (this->output == nullptr) return;

   this->output->setLevel(this->level);
}

NodeInput::NodeInput(const NodeInput * prototype) : Node() { }

NodeInput * NodeInput::clone() const {
	return new NodeInput(this);
}

// INPUT_LOW
NodeInputLow NodeInputLow::instance(NodeInputLow::type);
NodeInputLow::NodeInputLow(const char * type) : NodeInput() { }

// NodeInputLow::NodeInputLow(const NodeInputLow * prototype) : NodeInput() { }

// // INPUT_HIGH
// NodeInputHigh NodeInputHigh::instance(NodeInputHigh::type);
// NodeInputHigh::NodeInputHigh(const char * type) : NodeInput(type) { }
// NodeInputHigh::NodeInputHigh(const NodeInputHigh * prototype) : NodeInput() { }
