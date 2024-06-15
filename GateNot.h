#pragma once

#include "Node.h"

class GateNot : public Node {
public:
	GateNot();
	GateNot(const GateNot * prototype);
	virtual ~GateNot() = default;
	virtual GateNot * clone() const;
	SignalLevel level();

private:
	using Node::Node;
	constexpr static const char * type = "not";
	static GateNot instance;
};
