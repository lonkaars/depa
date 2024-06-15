#pragma once

#include "Node.h"

class NodeOutput : public Node {
public:
	NodeOutput();
	NodeOutput(const NodeOutput * prototype);
	~NodeOutput() = default;

	virtual void sim();
	virtual SignalLevel level();
	virtual NodeOutput * clone() const;
	virtual void setOutput(Net *);


private:
	using Node::Node;
	constexpr static const char * type = "probe";
	static NodeOutput instance;

private:
	SignalLevel input;

public:
	virtual void accept(NodeVisitor & visitor) { visitor.visit(*this); }
};

