#pragma once

#include "Node.h"

class NodeOutput : public Node {
public:
	NodeOutput(const NodeOutput * prototype);
	~NodeOutput() = default;
	virtual void sim();
	virtual NodeOutput * clone() const;

private:
	NodeOutput(const char * type);
	constexpr static const char * type = "probe";
	static NodeOutput instance;
};
