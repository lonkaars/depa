#pragma once

// #include "Node.h"
#include "GateAnd.h"

class GateNand : public GateAnd {
	using GateAnd::GateAnd;

protected:
	SignalLevel level();

private:
	GateNand(const char * type);
	constexpr static const char * type = "nand";
	static GateNand instance;
};

