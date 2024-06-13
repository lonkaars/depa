#pragma once

#include <string>
#include <vector>
#include <map>

#include "Node.h"
#include "Net.h"

using std::string;
using std::vector;

class Circuit {
public:
	Circuit() = default;
	virtual ~Circuit();

public:
	virtual void create(string label, vector<string> nodes);
	virtual void new_node(string label, string type);
	virtual void new_net(string src, vector<string> dests);
	virtual void sim();
	virtual string result();

private:
	std::map<string, Node *> nodes = {};
	vector<Net *> nets = {};

	virtual Node * find_node(string label);
};

