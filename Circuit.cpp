#include "Circuit.h"
#include "NodeFactory.h"

void Circuit::create(string label, vector<string> nodes) {
	if (nodes.size() == 1 && NodeFactory::has_type(nodes[0]))
		return new_node(label, nodes[0]);

	for (string node : nodes)
		new_net(label, node);
}

void Circuit::new_node(string label, string type) {
	printf("[%s] (%s)\n", label.c_str(), type.c_str());
}

void Circuit::new_net(string label, string connection) {
	printf("[%s] -> %s\n", label.c_str(), connection.c_str());
}

