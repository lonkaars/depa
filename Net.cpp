#include "Net.h"
#include <iostream>

Net::Net(){}

Net::~Net(){}

void Net::setLevel(SignalLevel level){
	this->level = level;
	std::cout << this->size() << std::endl;
	this->notify();
}

SignalLevel Net::getLevel(){
	return this->level;
}

