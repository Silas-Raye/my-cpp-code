#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
    int dist;
};

vector<Point> get_vertical_neighbors(const Point& p, int rows) {
    vector<Point> neighbors;
    if (p.x > 0)
        neighbors.push_back({p.x - 1, p.y});  // up
    if (p.x < rows - 1)
        neighbors.push_back({p.x + 1, p.y});  // down
    return neighbors;
}

vector<Point> get_horizontal_neighbors(const Point& p, int cols) {
    vector<Point> neighbors;
    if (p.y > 0)
        neighbors.push_back({p.x, p.y - 1});  // left
    if (p.y < cols - 1)
        neighbors.push_back({p.x, p.y + 1});  // right
    return neighbors;
}

// I had to split this into two functions to fix the cyclomatic complexity
vector<Point> get_neighbors(const Point& p, int rows, int cols) {
    vector<Point> neighbors = get_vertical_neighbors(p, rows);
    vector<Point> horizontal_neighbors = get_horizontal_neighbors(p, cols);
    neighbors.insert(
        neighbors.end(),
        horizontal_neighbors.begin(),
        horizontal_neighbors.end());
    return neighbors;
}

bool is_valid(const vector<string>& graph, const Point& p) {
    return graph[p.x][p.y] != '#';
}

int traverse(const vector<string>& graph) {
    int rows = graph.size();
    int cols = graph[0].length();
    Point start = {0, 0, 0};
    Point end = {rows - 1, cols - 1};

    // To keep track of whether we have visited a location
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Point> q;
    q.push(start);

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        // If this point is the end location, return the distance.
        if (p.x == end.x && p.y == end.y)
            return p.dist;

        // Otherwise, add all valid neighbors to the queue.
        vector<Point> neighbors = get_neighbors(p, rows, cols);
        for (const Point& neighbor : neighbors) {
            if (is_valid(graph, neighbor) && !visited[neighbor.x][neighbor.y]) {
                visited[neighbor.x][neighbor.y] = true;
                q.push({neighbor.x, neighbor.y, p.dist + 1});
            }
        }
    }
    return -1;
}
