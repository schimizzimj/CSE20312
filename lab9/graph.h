#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph{

	public:

		Graph();
		~Graph();
		void add_edge(char src, char dst); // add edge between two given nodes
		bool connects(char src, char dst); // check for a connection between two nodes
		void print(); // print graph, used for debugging
	private:

		unordered_map<char, vector<char>> edges; // stores the graph in adjacency list format	
};

#endif
