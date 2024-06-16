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
	//! create a new node or net
	virtual void create(string label, vector<string> nodes);
	//! simulate the circuit
	virtual void sim();
	//! get simulation results as formatted string (probe measure values)
	virtual string result();

private:
	//! specifically create new node
	virtual void new_node(string label, string type);
	//! specifically create a new net
	virtual void new_net(string src, vector<string> dests);

private:
	std::map<string, Node *> nodes = {};
	vector<Net *> nets = {};

	LoopDetection loops = LoopDetection();

	virtual Node * find_node(string label);
};

