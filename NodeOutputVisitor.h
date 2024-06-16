#pragma once

#include "NodeVisitor.h"
#include "NodeOutput.h"

class NodeOutputVisitor : public NodeVisitor {
public:
	NodeOutputVisitor() = default;
	virtual ~NodeOutputVisitor() = default;

	virtual void visit(Node & node);
	virtual void visit(NodeOutput & node);

	//! is the visited node a NodeOutput?
	bool output_node = false;
	//! input[0] level of NodeOutput
	SignalLevel level = UNDEFINED;
};

