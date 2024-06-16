#pragma once

#include "Node.h"

class GateOr : public Node {
	using Node::Node;

public:
	GateOr() = default;
	virtual ~GateOr() = default;
	virtual GateOr * clone() const;

public:
	SignalLevel level();

private:
	GateOr(const GateOr * prototype);
	constexpr static const char * type = "or";
	static GateOr instance;
};

