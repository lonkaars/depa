#include "NodeOutputVisitor.h"

void NodeOutputVisitor::visit(Node & node) { }
void NodeOutputVisitor::visit(NodeOutput & node) {
	level = node.level(); // TODO: dit klopt niet
	output_node = true;
}

