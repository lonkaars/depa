#pragma once

#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"

using std::string;
using std::vector;

class Node : Observer {
public:
	Node(const char * type);
	virtual ~Node() = default;
	void update();
	virtual void addInput(Net *);
	virtual void setOutput(Net *);
	virtual void compare() = 0;

protected:
	string label;

	vector<Net *> inputs;
	Net * output;
};

