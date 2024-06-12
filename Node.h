#pragma once

#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"

using std::string;
using std::vector;

class Node : Observer {
public:
	Node() = default;
	virtual ~Node() = default;
	virtual Node * clone() const = 0;

public:
	void update();
	virtual void addInput(Net *);
	virtual void setOutput(Net *);
	virtual void compare() = 0;

protected:
	Node(const char * type);

	string label;

	vector<Net *> inputs;
	Net * output;
};

