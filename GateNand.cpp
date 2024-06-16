#include "GateNand.h"

GateNand GateNand::instance(GateNand::type);

// GateNand::GateNand(const char * type) : GateAnd(type) { }

SignalLevel GateNand::level() {
	SignalLevel lvl = GateAnd::level();
	if (lvl == LOW) return HIGH;
	if (lvl == HIGH) return LOW;
	return UNDEFINED;
}

// GateNand::GateNand(const GateNand * prototype) : GateAnd() { }

GateNand * GateNand::clone() const {
	return new GateNand(this);
}

