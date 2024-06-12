#pragma once

#include "Node.h"

#include "prut.h"

class NodeInput : public Node {
public:
	NodeInput();
	~NodeInput() = default;

protected:
	NodeInput(const char * type) : Node(type) {}
};

class NodeInputLow : public NodeInput {
protected:
	SignalLevel level();
	NodeInputLow(const char * type) : NodeInput(type) {}
	NodeInputLow * clone() const;

private:
	NodeInputLow(const NodeInputLow *) : NodeInput() {}
	using NodeInput::NodeInput;
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;
};

class NodeInputHigh : public NodeInput {
protected:
	NodeInputHigh(const char * type) : NodeInput(type) {}

private:
	SignalLevel level();
	NodeInputHigh(const NodeInputHigh *) : NodeInput() {}
	NodeInputHigh * clone() const;

	using NodeInput::NodeInput;
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;
};

