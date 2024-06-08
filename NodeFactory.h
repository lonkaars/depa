#pragma once

#include <string>
#include <map>

#include "Node.h"

using std::string;

using NodeFactoryMap = std::map<string, const Node *>;

class NodeFactory {
public:
	NodeFactory() = default;
	virtual ~NodeFactory() = default;

public:
	static bool has_type(const char * type);
	static bool has_type(string type);
	static Node * create(string type);

private:
	static void assign(const char * type, const Node * node);
	static NodeFactoryMap & get_map();
	static string normalize_type(string type);
	static const Node * find_type(string type);

private:
	friend Node;
};

