#pragma once

#include "Node.h"

class GateOr : public Node {
public:
	GateOr() = default;
	GateOr(const GateOr * prototype);
	~GateOr() = default;
	virtual GateOr * clone() const;

protected:
	SignalLevel level();

private:
	using Node::Node;
	constexpr static const char * type = "or";
	static GateOr instance;
};

