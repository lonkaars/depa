#pragma once

#include "Node.h"

class NodeOutput : public Node {
	using Node::Node;

public:
	NodeOutput();
	virtual ~NodeOutput() = default;
	virtual NodeOutput * clone() const;

	virtual void sim();
	virtual void setOutput(Net *);

public:
	virtual SignalLevel level();

private:
	NodeOutput(const NodeOutput * prototype);
	constexpr static const char * type = "probe";
	static NodeOutput instance;

private:
	SignalLevel input;

public:
	virtual void accept(NodeVisitor & visitor) { visitor.visit(*this); }
};

