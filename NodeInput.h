#pragma once

#include "Node.h"

class NodeInput : public Node {
public:
	NodeInput() = default;
	NodeInput(const NodeInput * prototype);
	~NodeInput() = default;
	virtual void sim();
	SignalLevel level();
	virtual NodeInput * clone() const;

protected:
	NodeInput(const char * type);

private:
	SignalLevel input = UNDEFINED;
};

// Input LOW and HIGH unicorns:

class NodeInputLow : public NodeInput {
	using NodeInput::NodeInput;

public:
	// NodeInputLow(const NodeInputLow * prototype);
	// ~NodeInputLow() = default;
	// virtual void compare();
	// virtual NodeInputLow * clone() const;

private:
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;

	SignalLevel input = LOW;
};

class NodeInputHigh : public NodeInput {
private:
	using NodeInput::NodeInput;
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;

	SignalLevel input = HIGH;
};
