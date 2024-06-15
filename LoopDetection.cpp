#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#include "LoopDetection.h"
#include "Exception.h"

LoopDetection::~LoopDetection(){}

void LoopDetection::add_connection(const std::string &src, const std::vector<std::string> &dests)
{
	for (const auto &dest : dests) 
		adj_list[src].push_back(dest);
	
	if (detect_cycle(src))
		throw CircuitException( "Cycle detected starting from node: %s", src.c_str());
}

bool LoopDetection::detect_cycle(const std::string &start) {
	std::unordered_set<std::string> visited;
	std::unordered_set<std::string> rec_stack;

	return is_cyclic(start, visited, rec_stack);
}

bool LoopDetection::is_cyclic(const std::string &node, std::unordered_set<std::string> &visited, std::unordered_set<std::string> &rec_stack) {
	if (rec_stack.find(node) != rec_stack.end())
		return true; // Cycle/Loop detected

	if (visited.find(node) != visited.end())
		return false;

	visited.insert(node);
	rec_stack.insert(node);

	for (const auto &neighbor : adj_list[node])
		if (is_cyclic(neighbor, visited, rec_stack))
			return true;

	rec_stack.erase(node);
	return false;
}

