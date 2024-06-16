#pragma once

// #include "Node.h"
#include "GateOr.h"

class GateNor : public GateOr {
public:
	virtual GateNor * clone() const;

protected:
	SignalLevel level();
	using GateOr::GateOr;

private:
	GateNor(const GateNor *) : GateOr() {}
	// GateNor(const char * type);
	constexpr static const char * type = "nor";
	static GateNor instance;
};

