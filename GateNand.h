#pragma once

// #include "Node.h"
#include "GateAnd.h"

class GateNand : public GateAnd {
public:
	virtual GateNand * clone() const;

protected:
	SignalLevel level();
	using GateAnd::GateAnd;

private:
	GateNand(const GateNand *) : GateAnd() {}
	// GateNand(const char * type);
	constexpr static const char * type = "nand";
	static GateNand instance;
};

