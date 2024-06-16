#pragma once

#include "Node.h"

class GateNot : public Node {
	using Node::Node;

public:
	// \note max_inputs is overwritten here
	GateNot();
	virtual ~GateNot() = default;
	virtual GateNot * clone() const;

public:
	SignalLevel level();

private:
	GateNot(const GateNot * prototype);
	constexpr static const char * type = "not";
	static GateNot instance;
};
