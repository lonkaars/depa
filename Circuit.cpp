#include <format>

#include "Circuit.h"
#include "Exception.h"
#include "NodeFactory.h"

#include "NodeOutputVisitor.h"

using std::format;

void Circuit::create(string label, vector<string> nodes) {
	if (nodes.size() == 1 && NodeFactory::has_type(nodes[0]))
		return new_node(label, nodes[0]);

	new_net(label, nodes);
	ld->add_connection(label, nodes);
}

void Circuit::new_node(string label, string type) {
	if (nodes.find(label) != nodes.end())
		throw CircuitException("node with label \"%s\" already exists!", label.c_str());

	Node * node = NodeFactory::create(type);
	if (node == nullptr)
		throw CircuitException("unknown type \"%s\"", type.c_str());

	nodes[label] = node;
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
	}
}

void Circuit::sim() {
	for (auto & node : nodes)
		node.second->sim();
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

string Circuit::result() {
	string output;

	for (auto & n : nodes) {
		NodeOutputVisitor visitor;
		n.second->accept(visitor);
		if (!visitor.output_node) continue;

		output += format("{}: {}\n", n.first, std::to_string(visitor.level));
	}

	return output;
}

