#pragma once

#include "Node.h"

class NodeInput : public Node {
public:
	NodeInput();
	~NodeInput() = default;

	virtual void addInput(Net *);

protected:
	using Node::Node;
};

class NodeInputLow : public NodeInput {
public:
	virtual NodeInputLow * clone() const;

protected:
	SignalLevel level();
	using NodeInput::NodeInput;

private:
	NodeInputLow(const NodeInputLow *) : NodeInput() {}
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;
};

class NodeInputHigh : public NodeInput {
public:
	virtual NodeInputHigh * clone() const;

protected:
	SignalLevel level();
	using NodeInput::NodeInput;

private:
	NodeInputHigh(const NodeInputHigh *) : NodeInput() {}
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;
};

