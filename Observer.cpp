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

// TODO possibly add foo input as update value?
void Subject::notify() {
	for (int i = 0; i < this->observers.size(); i++)
		this->observers[i]->update();
}

