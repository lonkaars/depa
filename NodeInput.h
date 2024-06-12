#pragma once

#include "Node.h"

class NodeInput : public Node {
public:
   NodeInput() = default;
	NodeInput(const NodeInput * prototype);
	~NodeInput() = default;
	virtual void sim();
	SignalLevel level() { return UNDEFINED; };
	virtual NodeInput * clone() const;

private:
	NodeInput(const char * type);

	SignalLevel input = UNDEFINED;
};

// Input LOW and HIGH unicorns:

class NodeInputLow : public NodeInput {
public:
	// NodeInputLow(const NodeInputLow * prototype);
	// ~NodeInputLow() = default;
	// virtual void compare();
	// virtual NodeInputLow * clone() const;

private:
	NodeInputLow(const char * type);
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;

   SignalLevel input = LOW;
};

class NodeInputHigh : public NodeInput {
private:
   NodeInputHigh(const char * type);
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;

   SignalLevel input = HIGH;
};
