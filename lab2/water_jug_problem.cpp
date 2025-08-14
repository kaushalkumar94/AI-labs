#include <bits/stdc++.h>
using namespace std;

struct State
{
    int jug1, jug2;
};

void waterJug(int jug1Capacity, int jug2Capacity, int target)
{
    stack<State> st;
    set<pair<int, int>> visited;

    st.push({0, 0}); // start with both jugs empty

    while (!st.empty())
    {
        State curr = st.top();
        st.pop();
        if (visited.count({curr.jug1, curr.jug2}))
            continue;

        visited.insert({curr.jug1, curr.jug2});

        cout << "(" << curr.jug1 << ", " << curr.jug2 << ")\n";

        if (curr.jug1 == target || curr.jug2 == target)
        {
            cout << "Target achieved!\n";
            return;
        }

        st.push({jug1Capacity, curr.jug2});
        st.push({curr.jug1, jug2Capacity});
        st.push({0, curr.jug2});
        st.push({curr.jug1, 0});
        int pour = min(curr.jug1, jug2Capacity - curr.jug2);
        st.push({curr.jug1 - pour, curr.jug2 + pour});
        pour = min(curr.jug2, jug1Capacity - curr.jug1);
        st.push({curr.jug1 + pour, curr.jug2 - pour});
    }

    cout << "No solution found.\n";
}

int main()
{
    int jug1Capacity = 9;
    int jug2Capacity = 3;
    int target = 2;

    waterJug(jug1Capacity, jug2Capacity, target);

    return 0;
}