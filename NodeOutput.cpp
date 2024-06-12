#include "NodeOutput.h"
#include <iostream>

NodeOutput NodeOutput::instance(NodeOutput::type);

NodeOutput::NodeOutput(const char * type) : Node(type) { }

void NodeOutput::compare() {
   if (this->inputs.size() > 0) {
      std::cout << this->inputs[0]->getLevel() << std::endl;
   }
}

NodeOutput::NodeOutput(const NodeOutput * prototype) : Node() { }

NodeOutput * NodeOutput::clone() const {
	return new NodeOutput(this);
}