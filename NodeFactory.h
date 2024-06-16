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
	//! check if there is a node with type \p type
	static bool has_type(const char * type);
	//! check if there is a node with type \p type
	static bool has_type(string type);
	//! create a node with type \p type
	static Node * create(string type);

private:
	//! register a node with a type into the factory map
	static void assign(const char * type, const Node * node);
	//! retrieve the factory map
	static NodeFactoryMap & get_map();
	//! convert the type string for case insensitive matching
	static string normalize_type(string type);
	//! find a Node prototype by \p type
	static const Node * find_type(string type);

private:
	friend Node;
};

