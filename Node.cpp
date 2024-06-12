#include "Node.h"
#include "NodeFactory.h"

#include <iostream>

Node::Node(const char * type) {
	NodeFactory::assign(type, this);
}

void Node::addInput(Net* net) {
	net->attach(this);
}

void Node::setOutput(Net* net){
	this->output = net;
}

void Node::update(){
	std::cout << "updated" << std::endl;
	this->compare();
}

