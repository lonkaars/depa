#pragma once

#include "Node.h"

class GateAnd : public Node {
public:
	GateAnd() = default;
	GateAnd(const GateAnd * prototype);
	~GateAnd() = default;
	virtual GateAnd * clone() const;

protected:
	SignalLevel level();

	int min_inputs = 0;
	int max_inputs = -1;
	GateAnd(const char * type);

private:
	constexpr static const char * type = "and";
	static GateAnd instance;
};

