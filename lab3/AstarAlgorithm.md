# A* Grid Pathfinding — README

## Problem Statement
Given an \(n \times m\) grid where each cell is either traversable land (`1`) or an obstacle/river (`0`), find the **least-cost path** from a start cell `(sx, sy)` to a goal cell `(gx, gy)` using the A* search algorithm. Movement is allowed in **8 directions** (N, S, E, W, and four diagonals). Orthogonal moves cost `1`; diagonal moves cost `√2` by convention (the provided code currently uses `1.5`, which you can switch to `sqrt(2)` for geometrically accurate costs).

The program should:
- Validate that start/goal are on land.
- Compute a shortest (least-cost) path if one exists.
- Output the path cost, the sequence of coordinates, and a grid visualization marking the path.

---

## Input / Output Format
**Input** (interactive):
1. `n m` — grid dimensions (rows, columns)
2. `n` lines of `m` integers each (0 = obstacle, 1 = land)
3. Start position: `sx sy`
4. Goal position: `gx gy`
 
**Output**:
- If a path exists: prints total cost, list of coordinates in the path, and a grid visualization using:
  - `S` start, `E` end, `*` path, `#` obstacle, `.` traversable cell
- If no path exists: `No path found.`



## Solution Algorithm (A*) — Step by Step

### 1) Data Structures
- **Node**: `(x, y, g, h, path)` where
  - `g` = actual cost from start to this node
  - `h` = heuristic estimate from this node to goal
  - `f(n) = g + h` (priority in the frontier)
  - `path` = vector of coordinates from start to this node (simple but memory-heavy)
- **Frontier**: `priority_queue` ordered by smallest `f` (i.e., best-looking node first)
- **Closed set**: `visited` set of `(x, y)` already expanded

### 2) Initialization
- Compute `h(start) = heuristic(start, goal)` (Euclidean distance)
- Push the `start` node with `g = 0`, `h = heuristic` into the priority queue

### 3) Main Loop
Repeat until the frontier is empty:
1. **Pop** the node with the smallest `f = g + h`.
2. If this node is the **goal**, return its `path` and `g` as the final cost.
3. If the node was already expanded (in `visited`), **continue**.
4. **Mark** the node as visited.
5. **Generate neighbors** in 8 directions using `(dx, dy, moveCost)`:
   - Orthogonal moves: cost = `1`
   - Diagonal moves: cost = `sqrt(2)` recommended (`1.5` used in current code)
6. For each neighbor `(nx, ny)`:
   - If outside grid or cell is obstacle (`0`), **skip**.
   - If not visited, compute:
     - `g' = current.g + moveCost`
     - `h' = heuristic((nx, ny), goal)`
     - `f' = g' + h'`
   - **Push** a new node `(nx, ny, g', h', path + (nx, ny))` into the frontier.

If the frontier empties without reaching the goal, report **no path**.

> **Note on optimality:** With consistent/admissible heuristics and costs (`diag = sqrt(2)`), A* returns an optimal path. If you keep a hard `visited` set without checking for improved `g`-costs, you may miss better paths in rare layouts. The robust variant keeps a `gCost` map and pushes a node again if a cheaper path is found.

### 4) Heuristic Choice
- **Euclidean distance**: `sqrt(dx^2 + dy^2)` (used in code). Works well with 8-directional movement.
- For a perfect grid metric with `D=1` and diagonal `D2`:
  - **Octile distance** (admissible & consistent): `h = D*(dx + dy) + (D2 - 2D)*min(dx, dy)`
  - Use `D2 = sqrt(2)` for standard diagonal; or `D2 = 1.5` if you keep diagonal cost at `1.5`.


## Complexity Analysis
Let `N = n * m` be the number of cells.

### Time Complexity
- Each cell may be inserted into the priority queue multiple times, but with a proper `gCost` map typically each state is expanded at most once.
- Using a binary heap, A* runs in **O(E log V)** where `V = O(N)` and `E = O(8N)` ⇒ **O(N log N)**.
- **Implementation note:** This program stores an entire `path` vector in each queued node (copying it on every push). That adds overhead proportional to the path length per insertion. You can reduce constants by storing only a parent pointer (or predecessor map) and reconstructing the path at the end.

### Space Complexity
- Grid storage: **O(N)**
- Frontier (priority queue): up to **O(N)** in the worst case
- Visited/`gCost` structures: **O(N)**
- Path storage (current implementation): multiple copies may coexist in the queue, so peak usage can exceed **O(N)**. With parent pointers, it’s **O(N)**.

---
 
