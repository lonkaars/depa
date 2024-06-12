#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd() = default;
	GateAnd(const GateAnd * prototype);
	~GateAnd() = default;
	virtual GateAnd * clone() const;

private:
	SignalLevel level();

	using Node::Node;
	constexpr static const char * type = "and";
	static GateAnd instance;
};

