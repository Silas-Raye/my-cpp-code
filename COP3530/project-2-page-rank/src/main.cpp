#include "Graph.h"
using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    Graph Created_Graph;
    cin >> no_of_lines;
    cin >> power_iterations;
    for(int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        Created_Graph.insertEdge(from, to);
    }
    Created_Graph.getV();
    //Created_Graph.print();
    Created_Graph.pageRank(power_iterations);
}