#include "NodeOutputVisitor.h"

void NodeOutputVisitor::visit(Node & node) { }
void NodeOutputVisitor::visit(NodeOutput & node) {
	level = node.level();
	output_node = true;
}

