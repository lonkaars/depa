#include <locale>
#include <ranges>
#include <algorithm>

#include "NodeFactory.h"

bool NodeFactory::has_type(const char * type) {
	return has_type(string(type));
}

bool NodeFactory::has_type(string type) {
	std::ranges::transform(type, type.begin(), [] (unsigned char c) { return std::tolower(c); });

	// TODO: query the map instead
	if (type == "and") return true;
	if (type == "not") return true;
	if (type == "or") return true;
	if (type == "input_high") return true;
	if (type == "input_low") return true;
	if (type == "probe") return true;

	return false;
}

