#include "GateOr.h"

GateOr GateOr::instance(GateOr::type);

SignalLevel GateOr::level() {
	if (this->inputs.size() < 1) throw CircuitException("Or-gate input size error");

	SignalLevel new_level = LOW;
	for (int i = 0; i < this->inputs.size(); i++){
		SignalLevel l = this->inputs[i]->getLevel();

		if (l == UNDEFINED) return UNDEFINED;
		if (l == HIGH) new_level = HIGH;
	}
	return new_level;
}

GateOr::GateOr(const GateOr * prototype) : Node() { }

GateOr * GateOr::clone() const {
	return new GateOr(this);
}

