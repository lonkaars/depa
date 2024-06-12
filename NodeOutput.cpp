#include "NodeOutput.h"
#include "Exception.h"

#include <iostream>

NodeOutput NodeOutput::instance(NodeOutput::type);

NodeOutput::NodeOutput(const char * type) : Node(type) { }

void NodeOutput::sim() {
   if (this->inputs.size() == 0)
      throw CircuitException("No inputs on probe");

   std::cout << "Probe signal level: " << this->inputs[0]->getLevel() << std::endl;
}

NodeOutput::NodeOutput(const NodeOutput * prototype) : Node() { }

NodeOutput * NodeOutput::clone() const {
	return new NodeOutput(this);
}
