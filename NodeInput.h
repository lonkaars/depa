#pragma once

#include "Node.h"

#include "prut.h"

class NodeInput : public Node {
public:
	NodeInput() = default;
	NodeInput(const NodeInput * prototype);
	~NodeInput() = default;
	virtual NodeInput * clone() const;

protected:
	SignalLevel level();

private:
	using Node::Node;
	constexpr static const char * type = "input";
	static NodeInput instance;

private:
	int min_inputs = -1;
	int max_inputs = 0;
};

// class NodeInput : public Node {
// public:
// 	using Node::Node;
// 	NodeInput(const NodeInput * prototype);

// 	virtual NodeInput * clone() const;

// protected:
// 	SignalLevel level() = 0;

// private:
// 	NodeInput(const char * type);

// 	SignalLevel input = UNDEFINED;
// };

class NodeInputLow : public NodeInput {
protected:
	SignalLevel level();

private:
	using NodeInput::NodeInput;
	constexpr static const char * type = "input_low";
	static NodeInputLow instance;
};

class NodeInputHigh : public NodeInput {
private:
	SignalLevel level();

	using NodeInput::NodeInput;
	constexpr static const char * type = "input_high";
	static NodeInputHigh instance;
};

// class NodeInputHigh : public NodeInput {
// public:
// 	using NodeInput::NodeInput;
// 	virtual SignalLevel level();

// private:
// 	constexpr static const char * type = "input_high";
// 	static NodeInputHigh instance;
// };

