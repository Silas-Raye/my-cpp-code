#include "Graph.h"
using namespace std;

Graph::Graph() {
    v = 0;
    e = 0;
    graph = {};
}

void Graph::insertEdge(string from, string to) {
    graph[from].push_back(to);
    e++;
    if (graph.find(to)==graph.end())
        graph[to] = {};
}

void Graph::print() {
    cout << endl << "Graph created:" << endl;
    for (auto i : graph) {
        cout << i.first << ": ";
        for (auto j : i.second)
            cout << j << ", ";
        cout << endl;
    }
}

int Graph::getV() {
    for (auto i : graph) {
        v++;
    }
    return v;
}

int Graph::getE() {
    return e;
}

vector<double> Graph::multiplyMatrixWithVector(const vector<vector<double>>& matrix, const vector<double>& vec) {
    // Get the size of the matrix or vector.
    int V = matrix.size();

    // Initialize a resulting vector of size V.
    vector<double> resultVec(V, 0.0);

    // Traverse through each row of the matrix.
    for (int i = 0; i < V; i++) {
        // Calculating dot product for each row in the matrix with the vector and storing result in resultVec
        for (int j = 0; j < V; j++) {
            resultVec[i] += matrix[i][j] * vec[j];
        }
    }

    // Return the resulting vector.
    return resultVec;
}

void Graph::pageRank(int power_iterations) {
    // make matrix
    map<string, int> vertices;
    int id = 0;
    for (auto& kv : graph) {
        if (vertices.find(kv.first) == vertices.end()) {
            vertices[kv.first] = id++;
        }
        for (auto& v : kv.second) {
            if (vertices.find(v) == vertices.end()) {
                vertices[v] = id++;
            }
        }
    }

    int n = vertices.size();
    vector<vector<double>> matrix(n, vector<double>(n, 0));
    
    for(auto& keyValue: graph) {
        int j = vertices[keyValue.first];
        double dj = keyValue.second.size();
        for(auto& vi: keyValue.second) {
            int i = vertices[vi];
            matrix[i][j] = 1.0 / dj;
        }
    }

    // Printer
    // cout << endl << "Matrix:" << endl;
    // cout << "   ";
    // for(int j = 0; j < n; ++j)
    //     cout << j << " ";
    // cout << "\n";
    
    // for (int i = 0; i < n; ++i) {
    //     cout << i << " ";
    //     for (int j = 0; j < n; ++j) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << endl << "Key: \n";
    // for (auto& kv : vertices) {
    //     cout << kv.first << ": " << kv.second << "\n";
    // }
    // cout << endl;

    // make rt vec
    vector<double> rt;

    for (int i = 0; i < v; i++) 
        rt.push_back(1.0/v);

    // perform power iterations
    for (int i = 0; i < power_iterations - 1; i++) {
        // for (int i = 0; i < v; i++)
        //     cout << rt[i] << ", ";
        // cout << endl;
        rt = multiplyMatrixWithVector(matrix, rt);
    }

    // Printer
    // for (int i = 0; i < v; i++)
    //     cout << rt[i] << ", ";
    // cout << endl << endl;

    // final printer
    for (auto& kv : vertices) {
        cout << kv.first << " " << fixed << setprecision(2) << rt[kv.second] << "\n";
    }
}