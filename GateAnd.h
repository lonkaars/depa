#pragma once

#include "Node.h"

class GateAnd : public Node {
	using Node::Node;

public:
	GateAnd() = default;
	virtual ~GateAnd() = default;
	virtual GateAnd * clone() const;

public:
	SignalLevel level();

private:
	GateAnd(const GateAnd * prototype);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

