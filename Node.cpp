#include "Node.h"

#include <iostream>

Node::Node(const char * type) {

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

