/*
    Not so simple Graph

    Write C++ code for implementing a Graph data structure that supports a directed graph with 
    self-loops and parallel edges. You are expected to implement the following methods and a main
    method is already built for you:

        void *insertEdge*(int from, int to, int weight);   // 1
        bool *isEdge*(int from, int to);                   // 2
        int *sumEdge*(int from, int to);                   // 3
        vector<int> *getWeight*(int from, int to);         // 4
        vector<int> *getAdjacent*(int vertex);             // 5


    Sample Input:
        7    
        1 0 0 10  
        1 0 1 20 
        1 0 2 30
        2 0 0  
        3 0 2 
        4 0 1
        5 0
    
    Sample Output:
        1  
        30
        20 
        0 1 2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Graph
{
   private:
      // TODO: Graph structure that supports parallel edges and self-loops
      vector<vector<pair<int, int>>> adj;

    public:
      Graph();
      void insertEdge(int from, int to, int weight);  
      bool isEdge(int from, int to);  
      int sumEdge(int from, int to); 
      vector<int> getWeight(int from, int to); 
      vector<int> getAdjacent(int vertex); 
};

Graph::Graph() {}

void Graph::insertEdge(int from, int to, int weight) 
{
   /*
        TODO: insertEdge() adds a new edge between the from 
        and to vertex.
   */
    // Resize the adjacency list if 'from' or 'to' is greater than its current size.
    adj.resize(std::max(adj.size(), static_cast<size_t>(std::max(from, to) + 1)));

    // Insert an edge from 'from' to 'to' with 'weight'.
    adj[from].push_back({to, weight});

    // Make sure 'to' exists in the graph by adding an empty adjacency list for it, if it doesn't exist.
    if(adj.size() <= to) adj.resize(to + 1);

}
        
bool Graph::isEdge(int from, int to) 
{
    /*
        TODO: isEdge() returns a boolean indicating true 
        if there is an edge between the from and to vertex
    */
   for (const auto& edge: adj[from])
	{
        if (edge.first == to) // if there is a edge to the input to
		{
            return true;
        }
    }
    return false;
}

int Graph::sumEdge(int from, int to)
{
    /*
        TODO: sumEdge() returns the sum of weights of all edges 
        connecting the from and to vertex. Returns 0 if no edges 
        connect the two vertices.
    */
   int sum = 0;
	for (const auto& edge: adj[from])
	{
        if (edge.first == to)
		{
        	sum += edge.second; // add the weight of the edge
        }
	}
    return sum;
}

vector<int> Graph::getWeight(int from, int to)
{
    /*
        TODO: getWeight() returns a sorted vector containing all 
        weights of the edges connecting the from and to vertex
    */
    vector<int> weights;
	for (const auto& edge: adj[from])
	{
		if (edge.first == to)
		{
        	weights.push_back(edge.second);
        }
    }
    return weights;
}

vector<int> Graph::getAdjacent(int vertex) 
{
    /*
        TODO: getAdjacent() returns a sorted vector of all vertices
        that are connected to a vertex
    */
    vector<int> vertices;
	for (const auto& edge: adj[vertex])
	{
		vertices.push_back(edge.first);
    }
	sort(vertices.begin(), vertices.end());
    return vertices;
}
