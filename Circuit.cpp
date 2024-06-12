#include "Circuit.h"
#include "NodeFactory.h"

void Circuit::create(string label, vector<string> nodes) {
	if (nodes.size() == 1 && NodeFactory::has_type(nodes[0]))
		return new_node(label, nodes[0]);

	new_net(label, nodes);
}

void Circuit::new_node(string label, string type) {
	if (nodes.find(label) != nodes.end()) return; // TODO: exception!

	Node * node = NodeFactory::create(type);
	if (node == nullptr) return; // TODO: exception?

	nodes[label] = node;

	printf("[%s] (%s)\n", label.c_str(), type.c_str());
}

void Circuit::new_net(string src, vector<string> dests) {
	printf("%s\n", src.c_str());
	Net * net = new Net();
	nets.push_back(net);

	for (auto dest : dests) {
		Node * node = find_node(dest);
		if (node == nullptr) continue; // TODO: exception!
		node->addInput(net);
	}

	Node * node = find_node(src);
	if (node == nullptr) return; // TODO: exception!
	node->setOutput(net);
}

Node * Circuit::find_node(string label) {
	auto map_index = this->nodes.find(label);
	if (map_index == nodes.end()) return nullptr;
	return map_index->second;
}

Circuit::~Circuit() {
	for (auto & n : nodes)
		delete n.second;
	for (auto & n : nets)
		delete n;
}

