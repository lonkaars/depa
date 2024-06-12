#include "GateNot.h"

GateNot GateNot::instance(GateNot::type);

SignalLevel GateNot::level() {
	SignalLevel new_level = LOW;
	for (int i = 0; i < this->inputs.size(); i++){
		SignalLevel l = this->inputs[i]->getLevel();

		if (l == UNDEFINED) return UNDEFINED;
		if (l == HIGH) new_level = HIGH;
	}
	return new_level;
}

GateNot::GateNot(const GateNot * prototype) : Node() { }

GateNot * GateNot::clone() const {
	return new GateNot(this);
}
