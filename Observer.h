#pragma once
#include <vector>

class Observer {
public:
	virtual void update() = 0;
};

class Subject {
public:
	virtual void attach(Observer* obs);
	virtual void detach(Observer*);
	//! Get number of attached observers
	virtual int size();
	virtual void notify();

private:
	std::vector<Observer*> observers;
};

