#include "GateNot.h"

GateNot GateNot::instance(GateNot::type);

SignalLevel GateNot::level() {
	SignalLevel lvl = this->inputs[0]->getLevel();
	if (lvl == LOW) return HIGH;
	if (lvl == HIGH) return LOW;
	return UNDEFINED;
}

GateNot::GateNot(const GateNot * prototype) : Node() {
	this->min_inputs = 1;
	this->max_inputs = 1;
}

GateNot * GateNot::clone() const {
	return new GateNot(this);
}

