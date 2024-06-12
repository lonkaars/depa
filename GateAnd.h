#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd() {};
	GateAnd(const GateAnd * prototype);
	virtual ~GateAnd() = default;
	virtual void compare();
	virtual GateAnd * clone() const;

private:
	SignalLevel level();

	GateAnd(const char * type);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

