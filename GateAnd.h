#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd(const GateAnd * prototype);
	virtual ~GateAnd() = default;
	virtual void compare();
	virtual GateAnd * clone() const;

private:
	GateAnd(const char * type);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

