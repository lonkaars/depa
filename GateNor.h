#pragma once

#include "GateOr.h"

class GateNor : public GateOr {
	using GateOr::GateOr;

public:
	virtual GateNor * clone() const;

public:
	SignalLevel level();

private:
	GateNor(const GateNor *) : GateOr() {}
	constexpr static const char * type = "nor";
	static GateNor instance;
};

