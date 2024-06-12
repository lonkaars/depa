#include <iostream>

#include "Node.h"
#include "NodeFactory.h"
#include "Net.h"

Node::Node(const char * type) {
	NodeFactory::assign(type, this);
}

void Node::addInput(Net * net) {
	net->attach(this);
	inputs.push_back(net);
}

void Node::setOutput(Net * net){
	this->output = net;
}

void Node::update(){
	std::cout << "updated" << std::endl;
	this->sim();
}

