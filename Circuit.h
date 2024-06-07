#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Circuit {
public:
	Circuit() = default;
	virtual ~Circuit() = default;

public:
	void create(string label, vector<string> nodes);
	void new_node(string label, string type);
	void new_net(string label, string node);
};

