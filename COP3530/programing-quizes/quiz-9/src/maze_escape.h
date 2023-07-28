// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// struct Point {
//     int x;
//     int y;
//     int dist;
// };

// vector<Point> get_neighbors(const Point& p, int rows, int cols) {
//     vector<Point> neighbors;
//     if (p.x > 0)
//         neighbors.push_back({p.x - 1, p.y});  // up
//     if (p.y > 0)
//         neighbors.push_back({p.x, p.y - 1});  // left
//     if (p.x < rows - 1)
//         neighbors.push_back({p.x + 1, p.y});  // down
//     if (p.y < cols - 1)
//         neighbors.push_back({p.x, p.y + 1});  // right
//     return neighbors;
// }

// bool is_valid(const vector<string>& graph, const Point& p) {
//     return graph[p.x][p.y] != '#';
// }

// int traverse(vector<string>& graph) {
//     int rows = graph.size();
//     int cols = graph[0].length();
//     Point start = {0, 0, 0};
//     Point end = {rows - 1, cols - 1};
  
//     // To keep track of whether we have visited a location, we can use a 2D bool array
//     vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
//     queue<Point> q;
//     q.push(start);
    
//     while(!q.empty()) {
//         Point p = q.front();
//         q.pop();
        
//         // If this point is the end location, return the distance.
//         if (p.x == end.x && p.y == end.y)
//             return p.dist;
        
//         // Otherwise, add all valid neighbors to the queue.
//         vector<Point> neighbors = get_neighbors(p, rows, cols);
//         for (const Point& neighbor : neighbors) {
//             if (is_valid(graph, neighbor) && !visited[neighbor.x][neighbor.y]) {
//                 visited[neighbor.x][neighbor.y] = true;
//                 q.push({neighbor.x, neighbor.y, p.dist + 1});
//             }
//         }
//     }
//     return -1;
// }

#include <vector>
#include <queue>
#include <string>

using namespace std;

int traverse(vector<string>& graph) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    int rows = graph.size();
    int cols = graph[0].size();
    
    vector<vector<int>> visited(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;
    
    q.push({0,0});
    visited[0][0] = 0;
    
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int newX = node.first + dx[i];
            int newY = node.second + dy[i];
            
            if(newX >= 0 && newX < rows && newY >=0 && newY < cols && visited[newX][newY] == -1 && graph[newX][newY] != '#'){
                visited[newX][newY] = visited[node.first][node.second] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    return visited[rows-1][cols-1];
}
