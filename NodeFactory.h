#pragma once

#include <string>

#include "Node.h"

using std::string;

class NodeFactory {
public:
	NodeFactory() = default;
	virtual ~NodeFactory() = default;

public:
	static bool has_type(const char * type);
	static bool has_type(string type);

private:
	friend Node;
};

