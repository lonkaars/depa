#pragma once

#include "Node.h"

class GateXor : public Node {
public:
	GateXor() = default;
	GateXor(const GateXor * prototype);
	~GateXor() = default;
	virtual GateXor * clone() const;

private:
	SignalLevel level();

	using Node::Node;
	constexpr static const char * type = "xor";
	static GateXor instance;

private:
	int min_inputs = 1;
	int max_inputs = -1;
};
