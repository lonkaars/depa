#include <iostream>

#include "Observer.h"

void Subject::attach(Observer * obs){
	// std::cout << "added" << std::endl;
	this->observers.push_back(obs);
}

void Subject::detach(Observer *){

}

int Subject::size() {
	// std::cout << "subject list size " << this->observers.size() << std::endl;
	return this->observers.size();
}

void Subject::notify() {
	for (auto observer : this->observers)
		observer->update();
}

