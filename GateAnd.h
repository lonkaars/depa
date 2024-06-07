#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd(const char * type);
	virtual ~GateAnd() = default;
	virtual void compare();

private:
	constexpr static const char * type = "and";
	static GateAnd instance;
};

