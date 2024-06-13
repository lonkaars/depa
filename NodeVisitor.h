#pragma once

class Node;
class NodeOutput;

class NodeVisitor {
public:
	virtual void visit(NodeOutput & node) = 0;
	virtual void visit(Node & node) = 0;
};

