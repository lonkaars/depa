#pragma once

#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"

class Node: Observer {
protected:
	std::string label;
	std::string type;

	std::vector<Net*> inputs;
	Net* output;

public:
	Node(/* args */);
	virtual ~Node();
	void update();
	virtual void addInput(Net*);
	virtual void setOutput(Net*);
	virtual void compare() = 0;
};

class GateAnd: public Node {
public:
	GateAnd(){};
	~GateAnd(){};
	void compare();
};
