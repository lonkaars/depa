#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd() = default;
	~GateAnd() = default;
	virtual GateAnd * clone() const;

protected:
	SignalLevel level();

	using Node::Node;

private:
	GateAnd(const GateAnd * prototype);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

