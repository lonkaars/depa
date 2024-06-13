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
	virtual void init();
	NodeOutput(const char * type);
	constexpr static const char * type = "probe";
	static NodeOutput instance;
	SignalLevel input;

public:
	virtual void accept(NodeVisitor & visitor) { visitor.visit(*this); }
};

