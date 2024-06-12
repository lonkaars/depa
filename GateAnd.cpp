#include "GateAnd.h"

GateAnd GateAnd::instance(GateAnd::type);

SignalLevel GateAnd::level() {
	for (int i = 0; i < this->inputs.size(); i++){
		SignalLevel l = this->inputs[i]->getLevel();

		if (l == UNDEFINED) return UNDEFINED;
		if (l == LOW) return LOW;
	}
	return HIGH;
}

GateAnd::GateAnd(const GateAnd * prototype) : Node() { }

GateAnd * GateAnd::clone() const {
	return new GateAnd(this);
}

