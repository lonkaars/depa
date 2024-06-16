#pragma once

#include "Node.h"

class GateXor : public Node {
	using Node::Node;

public:
	GateXor() = default;
	virtual ~GateXor() = default;
	virtual GateXor * clone() const;

public:
	SignalLevel level();

private:
	GateXor(const GateXor * prototype);
	constexpr static const char * type = "xor";
	static GateXor instance;
};
