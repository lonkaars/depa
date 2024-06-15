#include "Observer.h"

void Subject::attach(Observer * obs) {
	this->observers.push_back(obs);
}

void Subject::detach(Observer *) { }

int Subject::size() {
	return this->observers.size();
}

void Subject::notify() {
	for (auto observer : this->observers)
		observer->update();
}

