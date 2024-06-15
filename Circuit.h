#pragma once

#include <string>
#include <vector>
#include <map>

#include "Node.h"
#include "Net.h"

#include "LoopDetection.h"

using std::string;
using std::vector;

class Circuit {
public:
	Circuit() = default;
	virtual ~Circuit();

public:
	//! Auto-magically creates either a new node or net
	virtual void create(string label, vector<string> nodes);
	//! Create new node (internal function)
	virtual void new_node(string label, string type);
	//! Create new net (internal function)
	virtual void new_net(string src, vector<string> dests);
	//! Simulate the circuit
	virtual void sim();
	//! Get simulation results (probe measure values)
	virtual string result();

private:
	std::map<string, Node *> nodes = {};
	vector<Net *> nets = {};

	LoopDetection * ld = new LoopDetection();

	virtual Node * find_node(string label);
};

