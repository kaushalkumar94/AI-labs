8-Puzzle Problem using BFS and DFS

Aim To solve the 8-puzzle problem using Breadth First Search (BFS) and Depth First Search (DFS) algorithms and compare their time and space complexities.

BFS Algorithm: Start with the initial puzzle configuration. Use a queue to store states to be explored.

Keep a visited set to avoid revisiting states.

Remove the first state from the queue.

If it is the goal state, stop.

Otherwise, generate all valid moves (up, down, left, right) and add the resulting states to the queue.

Repeat until the goal is found or the queue is empty.

Time Complexity: Worst case: O(b^d) , where

b = branching factor (average 2–3 for 8-puzzle)

d = depth of solution.

Space Complexity: O(b^d), because BFS stores all nodes at the current level in memory.

DFS Algorithm: Start with the initial puzzle configuration.

Use a stack (or recursion) to store states to be explored.

Keep a visited set to avoid infinite loops.

Pop the top state from the stack.

If it is the goal state, stop.

Otherwise, generate all valid moves (up, down, left, right) and push them onto the stack.

Repeat until the goal is found or the stack is empty.

Time Complexity: Worst case:** O(b^m)**, where b = branching factor m = maximum depth of the search tree.

Space Complexity: O(b*m) for recursive DFS (or linear in depth),

Less than BFS in general, but can still grow large if depth is big. BFS is complete and guarantees the shortest path but uses more memory.

DFS uses less memory but may go deep into useless paths and is not guaranteed to find the shortest path.

author Kaushal kumar
