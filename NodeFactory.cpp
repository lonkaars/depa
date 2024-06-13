#include <cassert>
#include <locale>
#include <ranges>
#include <algorithm>

#include "NodeFactory.h"

string NodeFactory::normalize_type(string type) {
	std::ranges::transform(type, type.begin(), [] (unsigned char c) { return std::tolower(c); });
	return type;
}

bool NodeFactory::has_type(const char * type) {
	return has_type(string(type));
}

bool NodeFactory::has_type(string type) {
	return find_type(type) != nullptr;
}

void NodeFactory::assign(const char * _type, const Node * node) {
	static NodeFactoryMap & map = get_map();
	string type = _type;
	type = normalize_type(type);

	// ensure there is only one class that registers a type
	assert(!has_type(type));

	// printf("map[\"%s\"] = %p\n", type.c_str(), node);
	map[type] = node;
}

NodeFactoryMap & NodeFactory::get_map() {
	static NodeFactoryMap map;
	return map;
}

const Node * NodeFactory::find_type(string type) {
	static NodeFactoryMap & map = get_map();
	type = normalize_type(type);
	if (!map.contains(type)) return nullptr;
	return map.find(type)->second;
}

Node * NodeFactory::create(string type) {
	const Node * prototype = find_type(type);
	if (prototype == nullptr) return nullptr;
	return prototype->clone();
}

