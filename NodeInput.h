#pragma once

#include "Node.h"

#include "prut.h"

class NodeInput : public Node {
public:
	using Node::Node;
	NodeInput(const NodeInput * prototype);

	virtual NodeInput * clone() const;

private:
	NodeInput(const char * type);

	SignalLevel input = UNDEFINED;
};

class NodeInputLow : public NodeInput {
public:
	using NodeInput::NodeInput;
	virtual SignalLevel level();

private:
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;
};

class NodeInputHigh : public NodeInput {
public:
	using NodeInput::NodeInput;
	virtual SignalLevel level();

private:
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;
};

