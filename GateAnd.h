#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd() = default;
	GateAnd(const GateAnd * prototype);
	~GateAnd() = default;
	virtual void sim();
	virtual GateAnd * clone() const;

private:
	GateAnd(const char * type);
	constexpr static const char * type = "and";
	static GateAnd instance;
};

