#include "GateXor.h"

GateXor GateXor::instance(GateXor::type);

SignalLevel GateXor::level() {
	bool on = false;
	for (int i = 0; i < this->inputs.size(); i++) {
		SignalLevel l = this->inputs[i]->getLevel();

		if (l == UNDEFINED) return UNDEFINED;
		if (l == HIGH) on = !on;
	}
	return on ? HIGH : LOW;
}

GateXor::GateXor(const GateXor * prototype) : Node() {}

GateXor * GateXor::clone() const {
	return new GateXor(this);
}

