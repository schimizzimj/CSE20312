/**
 * mst.cpp
 * Given the input of an undirected graph, this program computes and outputs the minimum spanning tree.
 *
 * Marcus Schimizzi
 * 5/3/17
 */

#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int minimum_cost(int cost[], bool frontier[], int dim);
void append_output(int parent[], int n, vector<vector<int>> &graph, int dim, vector<string> &out);
void prim_mst(vector<vector<int>> &graph, int dim, vector<string> &out);

int main() {
	int dimension;
	vector<string> output;
	while (cin >> dimension) {
		vector<vector<int>> graph(dimension, vector<int>(dimension));
		int input;
		for (int row = 0; row < dimension; row++) {
			for (int col = 0; col < dimension; col++) {
				cin >> input;
				graph[row][col] = input;
			}
		}
		prim_mst(graph, dimension, output);
	}
	for (auto it = output.begin(); it != output.end() - 1; ++it)
		cout << *it << endl;
}

int minimum_cost(int cost[], bool frontier[], int dim)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < dim; v++)
    	if (frontier[v] == false && cost[v] < min)
    		min = cost[v], min_index = v;
    return min_index;
}

void append_output(int parent[], int n, vector<vector<int>> &graph, int dim, vector<string> &output)
{
	vector<string> m;
	char a, b;
	string line = "";
	int sum = 0;

	for (int i = 1; i < dim; i++)
		sum += graph[i][parent[i]];
	output.push_back(to_string(sum));

    for (int i = 1; i < dim; i++) {
        a = (char)(i + 'A');
		b = (char)(parent[i] + 'A');
		if (a < b) {
			line = a;
			line += b;
		}else {
			line = b;
			line += a;
		}
		m.push_back(line);
	}
	sort(m.begin(), m.end());
	for (auto it = m.begin(); it != m.end(); ++it) {
		output.push_back(*it);
	}
	output.push_back("");
}

void prim_mst(vector<vector<int>> &graph, int dim, vector<string> &output)
{
    int parent[dim]; // stores minimum spanning tree
    int cost[dim]; // stores costs, allows picking of minimum weights
    bool frontier[dim]; // vertices not in minimum spanning tree

    for (int i = 0; i < dim; i++) // initialize costs to MAX, and frontier to false
        cost[i] = INT_MAX, frontier[i] = false;

    cost[0] = 0; // ensures the first vertex is picked first
    parent[0] = -1; // makes first node root of minimum spanning tree

    for (int count = 0; count < dim - 1; count++)
    {
        int u = minimum_cost(cost, frontier, dim);
        frontier[u] = true;

        for (int v = 0; v < dim; v++)
            if (graph[u][v] != -1 && frontier[v] == false && graph[u][v] < cost[v])
                parent[v] = u, cost[v] = graph[u][v];
    }
    append_output(parent, dim, graph, dim, output);
}
