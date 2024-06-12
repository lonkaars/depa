#include "Net.h"
#include <iostream>

#include "prut.h"

void Net::setLevel(SignalLevel level){
	this->level = level;
	this->notify();
}

SignalLevel Net::getLevel(){
	return this->level;
}

