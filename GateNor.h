#pragma once

// #include "Node.h"
#include "GateOr.h"

class GateNor : public GateOr {
private:
	SignalLevel level();

	// GateNor(const char * type);
	using GateOr::GateOr;
	constexpr static const char * type = "nor";
	static GateNor instance;
};

