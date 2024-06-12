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
	void create(string label, vector<string> nodes);
	void new_node(string label, string type);
	void new_net(string src, vector<string> dests);

private:
	std::map<string, Node *> nodes = {};
	vector<Net *> nets = {};
};

