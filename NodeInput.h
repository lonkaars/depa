#pragma once

#include "Node.h"

class NodeInput : public Node {
public:
	NodeInput() = default;
	NodeInput(const NodeInput * prototype);
	~NodeInput() = default;
	virtual void sim();
	virtual NodeInput * clone() const;

protected:
	using Node::Node;
	SignalLevel level = UNDEFINED;
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

	SignalLevel level = LOW;
};

class NodeInputHigh : public NodeInput {
private:
	using NodeInput::NodeInput;
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;

	SignalLevel level = HIGH;
};
