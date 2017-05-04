/** traversals.cpp
 * This program reads in a representation of a directed graph and a list of two nodes, and then is able to output whether or not there is a path from the first node in the list to the second one. 
 *
 * Marcus Schimizzi
 * 4/10/17
 */

#include <iostream>
#include <string>
using namespace std;

#include "graph.h"



int main() {
  char input, src, dst;
  vector<string> output; // stores all of output
  int count = 1; // current graph #
  while(cin >> input) { // run until the end of the stream
    if (count != 1)
	output.push_back(""); // add blank lines between graphs

    Graph g;
    input = (int)input - '0';
    for (int i = 0; i < input; i++) { // build graph
      cin >> src >> dst;
      g.add_edge(src, dst);
    }

    cin >> input;
    input = (int)input - '0';
    string current_test;
    string result;
    for (int i = 1; i <= input; i++) { // test all possible connections queried
        cin >> src >> dst;
        if (!g.connects(src, dst)) 
            result = "no";
	else result = "a";
	current_test = "In Graph " + to_string(count) + " there is " + result + " path from " + src + " to " + dst;
	output.push_back(current_test);	
    }     
	count++;
  }
    for (auto it = output.begin(); it != output.end(); ++it)
        cout << *it << endl; // print out output
}

