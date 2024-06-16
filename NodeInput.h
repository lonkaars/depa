#pragma once

#include "Node.h"

class NodeInput : public Node {
	using Node::Node;

public:
	NodeInput();
	~NodeInput() = default;

	//! override: throw exception
	virtual void addInput(Net *);
};

class NodeInputLow : public NodeInput {
	using NodeInput::NodeInput;

public:
	virtual NodeInputLow * clone() const;

public:
	SignalLevel level();

private:
	NodeInputLow(const NodeInputLow *) : NodeInput() {}
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;
};

class NodeInputHigh : public NodeInput {
	using NodeInput::NodeInput;

public:
	virtual NodeInputHigh * clone() const;

protected:
	SignalLevel level();

private:
	NodeInputHigh(const NodeInputHigh *) : NodeInput() {}
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;
};

