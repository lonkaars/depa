#pragma once

// #include "Node.h"
#include "GateAnd.h"

class GateNand : public GateAnd {
private:
	SignalLevel level();

	// GateNand(const char * type);
	using GateAnd::GateAnd;
	constexpr static const char * type = "nand";
	static GateNand instance;
};

