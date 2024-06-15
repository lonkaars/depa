#pragma once

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class LoopDetection {
public:
	LoopDetection() = default;
	virtual ~LoopDetection();

	//! Add connection and throws CircuitError if it creates a loop
	virtual void add_connection(const std::string &src, const std::vector<std::string> &dests);

private:
	std::unordered_map<std::string, std::vector<std::string>> adj_list;

	virtual bool detect_cycle(const std::string &start);
	virtual bool is_cyclic(const std::string &node, std::unordered_set<std::string> &visited, std::unordered_set<std::string> &rec_stack);
};
