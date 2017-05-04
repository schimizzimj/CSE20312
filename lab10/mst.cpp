/**
 * mst.cpp
 * Given the input of an undirected graph, this program computes and outputs the minimum spanning tree.
 *
 * Marcus Schimizzi
 * 5/3/17
 */

#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	int dimension;
	while (cin >> dimension) {
		int matrix[dimension][dimension];
		for (int row = 0; row < dimension; row++) {
			for (int col = 0; col < dimension; col++) {
				cin >> matrix[row][col]; 
			}
		}
		
	}
	
}

int minKey(int key[], bool mstSet[], int dim)
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < dim; v++)
    if (mstSet[v] == false && key[v] < min)
    min = key[v], min_index = v;
 
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V])
{
    cout<<"Edge   Weight\n";
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST
 

    for (int count = 0; count < V - 1; count++)
    {

        int u = minKey(key, mstSet);

        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent, V, graph);
}



