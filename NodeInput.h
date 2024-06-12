#pragma once

#include "Node.h"

#include "prut.h"

class NodeInput : public Node {
public:
	using Node::Node;
	NodeInput(const NodeInput * prototype);

	virtual NodeInput * clone() const;

protected:
	virtual SignalLevel level();
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

