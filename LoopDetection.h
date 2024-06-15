#pragma once

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class LoopDetection {
public:
	LoopDetection() = default;
	virtual ~LoopDetection();

	//! Add connection and throws CircuitError if it creates a loop
	virtual void add_connection(const string &src, const vector<string> &dests);

private:
	unordered_map<string, vector<string>> adj_list;

	virtual bool detect_cycle(const string &start);
	virtual bool is_cyclic(const string &node, unordered_set<string> &visited, unordered_set<string> &rec_stack);
};
