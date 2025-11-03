#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    double g, h;
    vector<pair<int,int>> path;

    double f() const { return g + h; }

    bool operator>(const Node &other) const {
        return f() > other.f();
    }
};

double heuristic(pair<int,int> a, pair<int,int> b) {
    int dx = abs(a.first - b.first);
    int dy = abs(a.second - b.second);
    // Euclidean heuristic
    return sqrt(dx*dx + dy*dy);
}

vector<pair<int,int>> a_star(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> goal, double &finalCost) {
    int rows = grid.size();
    int cols = grid[0].size();

    // 8 directions: (dx, dy, cost)
    vector<tuple<int,int,double>> directions = {
        make_tuple(-1, 0, 1), make_tuple(1, 0, 1), 
        make_tuple(0, -1, 1), make_tuple(0, 1, 1),
        make_tuple(-1, -1, 1.5), make_tuple(-1, 1, 1.5), 
        make_tuple(1, -1, 1.5), make_tuple(1, 1, 1.5)
    };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<pair<int,int>> visited;

    Node startNode{start.first, start.second, 0, heuristic(start, goal), {start}};
    pq.push(startNode);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (visited.count({current.x, current.y})) continue;
        visited.insert({current.x, current.y});

        if (make_pair(current.x, current.y) == goal) {
            finalCost = current.g;
            return current.path;
        }

        for (size_t i = 0; i < directions.size(); i++) {
            int dx = get<0>(directions[i]);
            int dy = get<1>(directions[i]);
            double cost = get<2>(directions[i]);

            int nx = current.x + dx;
            int ny = current.y + dy;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                if (!visited.count({nx, ny})) {
                    double newG = current.g + cost;
                    double newH = heuristic({nx, ny}, goal);
                    auto newPath = current.path;
                    newPath.push_back({nx, ny});
                    pq.push({nx, ny, newG, newH, newPath});
                }
            }
        }
    }

    finalCost = INFINITY;
    return {}; // no path
}

void printGrid(vector<vector<int>> &grid, vector<pair<int,int>> &path, pair<int,int> start, pair<int,int> goal) {
    int rows = grid.size(), cols = grid[0].size();
    set<pair<int,int>> pathSet(path.begin(), path.end());

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (make_pair(i, j) == start) cout << "S "; // Start
            else if (make_pair(i, j) == goal) cout << "E "; // End
            else if (pathSet.count({i, j})) cout << "* "; // Path
            else if (grid[i][j] == 0) cout << "# "; // Obstacle
            else cout << ". "; // Land
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter grid size (rows cols): ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid row by row (0 = river, 1 = land):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int sx, sy, gx, gy;
    cout << "Enter start position (row col): ";
    cin >> sx >> sy;
    cout << "Enter goal position (row col): ";
    cin >> gx >> gy;

    if (grid[sx][sy] == 0 || grid[gx][gy] == 0) {
        cout << "Invalid start or goal (on water).\n";
        return 0;
    }

    double cost;
    vector<pair<int,int>> path = a_star(grid, {sx, sy}, {gx, gy}, cost);

    if (!path.empty()) {
        cout << "Path found with cost " << cost << ":\n";
        for (auto &p : path) cout << "(" << p.first << "," << p.second << ") ";
        cout << "\n\nGrid visualizaton:\n";
        printGrid(grid, path, {sx, sy}, {gx, gy});
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
