#pragma once

#include "NodeVisitor.h"
#include "NodeOutput.h"

class NodeOutputVisitor : public NodeVisitor {
public:
	NodeOutputVisitor() = default;
	virtual ~NodeOutputVisitor() = default;

	virtual void visit(Node & node);
	virtual void visit(NodeOutput & node);

	bool output_node = false;
	SignalLevel level = UNDEFINED;
};

