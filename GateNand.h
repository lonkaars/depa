#pragma once

#include "GateAnd.h"

class GateNand : public GateAnd {
	using GateAnd::GateAnd;

public:
	virtual GateNand * clone() const;

public:
	SignalLevel level();

private:
	GateNand(const GateNand *) : GateAnd() {}
	constexpr static const char * type = "nand";
	static GateNand instance;
};

