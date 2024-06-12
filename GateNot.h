#pragma once

#include "Node.h"

class GateNot : public Node {
public:
	GateNot() = default;
	GateNot(const GateNot * prototype);
	~GateNot() = default;
	virtual GateNot * clone() const;

private:
	SignalLevel level();

	using Node::Node;
	constexpr static const char * type = "Not";
	static GateNot instance;

private:
	int min_inputs = 1;
	int max_inputs = 1;
};
