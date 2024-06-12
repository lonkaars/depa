#pragma once
#include <vector>

class Observer {
private:

public:
	virtual void update();

};

class Subject {
private:
	std::vector<Observer*> observers;
public:
	// virtual void attach(Observer* obs) { observers.push_back(obs);}
	virtual void attach(Observer* obs);
	virtual void detach(Observer*);
	virtual int size();

	// TODO possibly add foo input as update value?
	virtual void notify();
	// virtual void notify() {
	// 	for (int i = 0; i < observers.size(); i++)
	// 		observers.at(i)->update();
	// }
};

