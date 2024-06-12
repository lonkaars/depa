#include <iostream>

#include "Observer.h"

void Subject::attach(Observer * obs){
	this->observers.push_back(obs);
}

void Subject::detach(Observer *){

}

int Subject::size() {
	return this->observers.size();
}

// TODO possibly add foo input as update value?
void Subject::notify() {
	for (int i = 0; i < this->observers.size(); i++)
		this->observers[i]->update();
}

