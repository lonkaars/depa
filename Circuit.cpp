#include "Circuit.h"
#include "Exception.h"
#include "NodeFactory.h"

#include "prut.h"

void Circuit::create(string label, vector<string> nodes) {
	if (nodes.size() == 1 && NodeFactory::has_type(nodes[0]))
		return new_node(label, nodes[0]);

	new_net(label, nodes);
}

void Circuit::new_node(string label, string type) {
	if (nodes.find(label) != nodes.end())
		throw CircuitException("node with label \"%s\" already exists!", label.c_str());

	Node * node = NodeFactory::create(type);
	if (node == nullptr)
		throw CircuitException("unknown type \"%s\"", type.c_str());

	nodes[label] = node;

	prutprintf("[%s] (%s)", label.c_str(), type.c_str());
}

void Circuit::new_net(string src, vector<string> dests) {
	Net * net = new Net();
	nets.push_back(net);

	Node * node = find_node(src);
	if (node == nullptr)
		throw CircuitException("unknown source node \"%s\"", src.c_str());
	node->setOutput(net);

	for (auto dest : dests) {
		Node * node = find_node(dest);
		if (node == nullptr)
			throw CircuitException("unknown destination node \"%s\"", dest.c_str());
		node->addInput(net);
		prutprintf("%s -> %s", src.c_str(), dest.c_str());
	}
}

void Circuit::sim() {
	for (auto & node : nodes) {
		node.second->sim();
	}
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

