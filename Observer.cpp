#include "Observer.h"
#include <iostream>

void Observer::update(){
	std::cout << 'a' << std::endl;
}


void Subject::attach(Observer* obs){
	std::cout << "added" << std::endl;
	this->observers.push_back(obs);
}

void Subject::detach(Observer*){

}

int Subject::size() {
	std::cout << "subject list size " << this->observers.size() << std::endl;
	return this->observers.size();
}

// TODO possibly add foo input as update value?
void Subject::notify() {
	for (int i = 0; i < this->observers.size(); i++)
		this->observers[i]->update();
}

