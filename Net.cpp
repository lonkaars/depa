#include "Net.h"
#include <iostream>

#include "prut.h"

void Net::setLevel(SignalLevel level){
	this->level = level;
	// std::cout << this->size() << std::endl;
	prutprintf("%u", this->size());
	

	this->notify();
}

SignalLevel Net::getLevel(){
	return this->level;
}

