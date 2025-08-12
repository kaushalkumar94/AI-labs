#include <bits/stdc++.h>
using namespace std;

struct Node {
    string state;
    string path;  
};

 
string goal = "123456780";  
 
vector<pair<int, int>> moves = {
    {-1, 0},  
    {1, 0},   
    {0, -1},  
    {0, 1}   
};

 
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

 
void solveBFS(string start) {
    queue<Node> q;
    unordered_set<string> visited;

    q.push({start, ""});
    visited.insert(start);

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

    
        if (current.state == goal) {
            cout << "solution found: " << current.path << "\n";
            cout << "number of moves: " << current.path.size() << "\n";
            return;
        }

       
        int zeroPos = current.state.find('0');
        int x = zeroPos / 3;
        int y = zeroPos % 3;

    
        for (int i = 0; i < 4; i++) {
            int nx = x + moves[i].first;
            int ny = y + moves[i].second;

            if (isValid(nx, ny)) {
                string newState = current.state;
                swap(newState[x * 3 + y], newState[nx * 3 + ny]);

                if (!visited.count(newState)) {
                    visited.insert(newState);
                    q.push({newState, current.path + "UDLR"[i]});
                }
            }
        }
    }
    cout << "no solution \n";
}

int main() {
  
    string start = "125340678";  

    solveBFS(start);

    return 0;
}
