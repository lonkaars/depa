#pragma once

#include "Node.h"

class GateAnd : public Node {
	using Node::Node;

public:
	GateAnd() = default;
	~GateAnd() = default;
	virtual GateAnd * clone() const;

protected:
	SignalLevel level();

private:
	GateAnd(const GateAnd * prototype);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

