#include <locale>
#include <ranges>
#include <algorithm>

#include "NodeFactory.h"

bool NodeFactory::has_type(const char * type) {
	return has_type(string(type));
}

bool NodeFactory::has_type(string type) {
	std::ranges::transform(type, type.begin(), [] (unsigned char c) { return std::tolower(c); });

	static NodeFactoryMap & map = get_map();

	return map.find(type) != map.end();
}

void NodeFactory::assign(const char * _type, const Node * node) {
	static NodeFactoryMap & map = get_map();
	string type = _type;

	std::ranges::transform(type, type.begin(), [] (unsigned char c) { return std::tolower(c); });

	if (has_type(type)) return;

	map[type] = node;
}

NodeFactoryMap & NodeFactory::get_map() {
	static NodeFactoryMap map;
	return map;
}

