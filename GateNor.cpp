#include "GateNor.h"

GateNor GateNor::instance(GateNor::type);

// GateNor::GateNor(const char * type) : Node(type) { }

SignalLevel GateNor::level() {
	SignalLevel lvl = GateOr::level();
	if (lvl == LOW) return HIGH;
	if (lvl == HIGH) return LOW;
	return UNDEFINED;
}

// GateNor::GateNor(const GateNor * prototype) : Node() { }

GateNor * GateNor::clone() const {
	return new GateNor(this);
}

