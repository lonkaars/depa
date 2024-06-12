#include "Net.h"
#include <iostream>

#include "prut.h"

void Net::setLevel(SignalLevel level){
	// if (this->level == level) return;
	this->level = level;
	this->notify();
}

SignalLevel Net::getLevel(){
	return this->level;
}

