#include "GateAnd.h"
#include "Exception.h"

GateAnd GateAnd::instance(GateAnd::type);

GateAnd::GateAnd(const char * type) : Node(type) { }

SignalLevel GateAnd::level() {
	if (this->inputs.size() < 1) throw CircuitException("AndGate input size error");

	for (int i = 0; i < this->inputs.size(); i++){
		SignalLevel l this->inputs[i]->getLevel();

		if (l == UNDEFINED) return UNDEFINED;
		if (l == LOW) return LOW;
	}
	return HIGH;
}

// Concrete Nodes:
void GateAnd::sim() {
	SignalLevel new_out = this->level();

	if (new_out == UNDEFINED) return;

	printf("io size: %lu\n", this->inputs.size());
	// TODO: fix segfault somewhere below



	if (this->output->getLevel() == new_out) return;

	this->output->setLevel(new_out);
}

GateAnd::GateAnd(const GateAnd * prototype) : Node() { }

GateAnd * GateAnd::clone() const {
	return new GateAnd(this);
}

