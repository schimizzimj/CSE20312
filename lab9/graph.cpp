#include "graph.h"
#include <iostream>

Graph::Graph() // default constructor
{ }

Graph::~Graph() // default destructor
{ }

void Graph::add_edge(char src, char dst) {

	vector<char> v;
	auto m = edges.find(src); // check if src is in the graph
	if (m == edges.end() ) { // if not, add it and its value
		v.push_back(dst);
		edges[src] = v;
	}else{
		m->second.push_back(dst); // if so, append its value
	}

	auto n = edges.find(dst); // check if dst is in the graph
	if (n == edges.end()) { // if not, add it and an empty vector for its value
		vector<char> a;
		edges[dst] = a;
	}
}

void Graph::print() {
	// iterate through the graph and print for debugging
	for (auto it = edges.begin(); it != edges.end(); ++it) {

		cout << it->first << ":: ";
		for (auto t = it->second.begin(); t != it->second.end(); ++t)
			cout << *t << " ";
		cout << endl;
	}
}

bool Graph::connects(char src, char dst) {

	queue<char> frontier; // stores next node to visit and check connections
	vector<bool> marked (edges.size(), false); // stores visited nodes
	
	frontier.push(src);

	while(!frontier.empty()) {
		char current = frontier.front();
		if (current == dst) // check if this node is destination
			return true;
		
		frontier.pop();
		if (marked[(int)current - 'A']) // if it is already marked, just move on
			continue;
		marked[(int)current - 'A'] = true; // else, mark it as visited

		for (unsigned int i = 0; i < edges[current].size(); ++i) {
			// iterate though edges, and add them to the frontier	
			frontier.push(edges[current][i]);	
		}
	}
	return false;
}
