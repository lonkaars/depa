#pragma once

#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"
#include "NodeVisitor.h"

using std::string;
using std::vector;

class Node : Observer {
public:
	Node() = default;
	virtual ~Node() = default;
	virtual Node * clone() const = 0;

public:
	//! alias to \p sim() for Observer
	void update();
	//! add input to node
	virtual void addInput(Net *);
	//! set output net
	virtual void setOutput(Net *);
	//! simulate node behavior (calculate new level and notify outputs)
	virtual void sim();

public:
	//! calculate the new logic level
	virtual SignalLevel level() = 0;

protected:
	Node(const char * type);

	vector<Net *> inputs;
	Net * output = nullptr;

protected:
	int min_inputs = 2; // at least 2 inputs for most gates
	int max_inputs = -1; // unlimited

public:
	virtual void accept(NodeVisitor & visitor) { visitor.visit(*this); }
	friend NodeVisitor;
};

