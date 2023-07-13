#pragma once
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>
using namespace std;

class Graph {
    private:
        int v; //Number of vertices
        int e; //Number of edges
        map<string, vector<string>> graph; //Adjacency list

        vector<double> multiplyMatrixWithVector(const vector<vector<double>>& matrix, const vector<double>& vec);

    public:
        Graph();

        void insertEdge(string from, string to);
        void print();
        int getV();
        int getE();
        void pageRank(int power_iterations);
};