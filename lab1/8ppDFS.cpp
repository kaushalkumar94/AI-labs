#include <bits/stdc++.h>
using namespace std;

string target = "123456780"; 

vector<vector<int>> moves = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool isValid(int r, int c) {
    return r >= 0 && r < 3 && c >= 0 && c < 3;
}

int bfs(string start) {
    if (start == target) return 0;

    queue<pair<string, int>> q;  
    unordered_set<string> visited;

    visited.insert(start);
    q.push(make_pair(start, 0));  

    while (!q.empty()) {
        pair<string, int> front = q.front();
        string state = front.first;
        int depth = front.second;
        q.pop();

        int zeroPos = state.find('0');
        int r = zeroPos / 3, c = zeroPos % 3;

        for (size_t i = 0; i < moves.size(); i++) {
            int nr = r + moves[i][0];
            int nc = c + moves[i][1];
            if (isValid(nr, nc)) {
                string newState = state;
                swap(newState[r * 3 + c], newState[nr * 3 + nc]);
                if (newState == target) return depth + 1;
                if (visited.count(newState) == 0) {
                    visited.insert(newState);
                    q.push(make_pair(newState, depth + 1));
                }
            }
        }
    }
    return -1;  
}

int main() {
    string start = "123405786";  
    int steps = bfs(start);
    if (steps != -1)
        cout << "solved in " << steps << " moves using BFS.\n";
    else
        cout << "no solution\n";
    return 0;
}
