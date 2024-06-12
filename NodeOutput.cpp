#include "NodeOutput.h"
#include "Exception.h"

#include "prut.h"

NodeOutput NodeOutput::instance(NodeOutput::type);

NodeOutput::NodeOutput(const char * type) : Node(type) { }

void NodeOutput::sim() {
   if (this->inputs.size() == 0)
      throw CircuitException("No inputs on probe");

	 prutprintf("level: %u", this->inputs[0]->getLevel());
}

NodeOutput::NodeOutput(const NodeOutput * prototype) : Node() { }

NodeOutput * NodeOutput::clone() const {
	return new NodeOutput(this);
}
