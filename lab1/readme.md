# AI Lab 1 - Classical Search Algorithms

This repository contains implementations of classical AI search algorithms applied to well-known problems: the 8-Puzzle Problem and the Water Jug Problem.

## Repository Structure
```
lab1/
├── 8puzzle_bfs_path.cpp      # 8-Puzzle solver using BFS (with path tracking)
├── 8puzzle_bfs_count.cpp     # 8-Puzzle solver using BFS (move counter)
└── water_jug_dfs.cpp          # Water Jug problem solver using DFS
```

## Problems Overview

### 1. 8-Puzzle Problem

The 8-puzzle consists of a 3×3 grid containing tiles numbered 1-8 and one empty space (represented by 0). The objective is to rearrange the tiles from an initial configuration to a goal configuration by sliding tiles into the empty space.

**Goal State:**
```
1 2 3
4 5 6
7 8 0
```

**Valid Moves:**
- **U (Up)** - Move empty space upward
- **D (Down)** - Move empty space downward  
- **L (Left)** - Move empty space left
- **R (Right)** - Move empty space right

### 2. Water Jug Problem

Given two jugs with different capacities and an infinite water source, measure an exact target amount of water using only these operations:
- Fill a jug completely
- Empty a jug completely
- Pour water from one jug to another

**Example:** With jugs of capacity 9L and 3L, measure exactly 2L.

## Implementations

### 8-Puzzle Solver - BFS with Path Tracking

**File:** `8puzzle_bfs_path.cpp`

**Description:** Solves the 8-puzzle using Breadth-First Search and returns the complete solution path showing the sequence of moves (U/D/L/R).

**Features:**
- Finds optimal (shortest) solution
- Tracks complete move sequence
- Returns both path and number of moves

**Algorithm:**
1. Start with initial state in queue
2. Explore states level by level (BFS)
3. For each state, generate all valid moves
4. Track path by appending move character (U/D/L/R)
5. Return when goal state is reached

**Example Output:**
```
solution found: RDLURD
number of moves: 6
```

**Complexity:**
- **Time:** O(b^d) where b=4 (branching factor), d=solution depth
- **Space:** O(b^d) for queue and visited set

### 8-Puzzle Solver - BFS Move Counter

**File:** `8puzzle_bfs_count.cpp`

**Description:** Solves the 8-puzzle using BFS but only returns the minimum number of moves required, making it more memory efficient.

**Features:**
- Finds optimal solution depth
- Memory efficient (no path storage)
- Early termination when goal found

**Algorithm:**
1. Start with initial state and depth 0
2. Explore states level by level
3. Track depth alongside each state
4. Return depth immediately when goal found

**Example Output:**
```
solved in 3 moves using BFS.
```

**Complexity:**
- **Time:** O(b^d) where b=4, d=solution depth
- **Space:** O(b^d) but more efficient than path tracking version

### Water Jug Problem - DFS

**File:** `water_jug_dfs.cpp`

**Description:** Solves the water jug problem using Depth-First Search with a stack-based approach.

**Features:**
- Explores all 6 possible operations
- Prints state exploration sequence
- Finds any valid solution (not necessarily optimal)

**Algorithm:**
1. Start with both jugs empty (0, 0)
2. Use stack for DFS traversal
3. Generate 6 possible next states:
   - Fill jug 1
   - Fill jug 2
   - Empty jug 1
   - Empty jug 2
   - Pour jug 1 → jug 2
   - Pour jug 2 → jug 1
4. Continue until target amount is found

**Example Output:**
```
(0, 0)
(9, 0)
(9, 3)
(0, 3)
(3, 0)
(3, 3)
(6, 0)
(6, 3)
(0, 2)
Target achieved!
```

**Complexity:**
- **Time:** O(m × n) where m=jug1 capacity, n=jug2 capacity
- **Space:** O(m × n) for stack and visited set

## Compilation and Execution

### Prerequisites
- C++ compiler supporting C++11 or higher (g++, clang++)

### Compile Commands
```bash
# 8-Puzzle BFS with path
g++ -std=c++11 8puzzle_bfs_path.cpp -o 8puzzle_path
./8puzzle_path

# 8-Puzzle BFS move counter
g++ -std=c++11 8puzzle_bfs_count.cpp -o 8puzzle_count
./8puzzle_count

# Water Jug DFS
g++ -std=c++11 water_jug_dfs.cpp -o water_jug
./water_jug
```

## Modifying Input

### 8-Puzzle Programs

Edit the `start` string in `main()`:
```cpp
string start = "125340678";  // Your initial configuration
```

String represents the puzzle in row-major order:
```
Position: 0 1 2 3 4 5 6 7 8
Grid:     1 2 5
          3 4 0
          6 7 8
```

### Water Jug Program

Edit the parameters in `main()`:
```cpp
int jug1Capacity = 9;  // First jug capacity
int jug2Capacity = 3;  // Second jug capacity
int target = 2;        // Target amount to measure
```

## Algorithm Comparison

| Algorithm | Problem | Optimality | Time Complexity | Space Complexity |
|-----------|---------|------------|-----------------|------------------|
| BFS (path) | 8-Puzzle | Optimal | O(b^d) | O(b^d) |
| BFS (count) | 8-Puzzle | Optimal | O(b^d) | O(b^d) |
| DFS | Water Jug | Non-optimal | O(m×n) | O(m×n) |

**Key Differences:**
- **BFS** guarantees shortest path but uses more memory
- **DFS** uses less memory but doesn't guarantee optimal solution
- **BFS** explores level by level (queue-based)
- **DFS** explores depth first (stack-based)

## Problem Solvability

### 8-Puzzle
Not all configurations are solvable. A puzzle is solvable if the number of inversions is even (excluding the blank tile).

### Water Jug
Solvable if and only if:
- Target ≤ max(jug1Capacity, jug2Capacity)
- Target is a multiple of GCD(jug1Capacity, jug2Capacity)

## Key Concepts Demonstrated

1. **State Space Search** - Representing problems as graphs of states
2. **BFS (Breadth-First Search)** - Level-by-level exploration, guarantees optimal solution
3. **DFS (Depth-First Search)** - Depth-first exploration, memory efficient
4. **Visited Set** - Preventing infinite loops and redundant exploration
5. **State Representation** - Encoding complex states efficiently

## Limitations

### 8-Puzzle Implementations
- No solvability check before search
- Memory intensive for deep solutions
- Not scalable to larger puzzles (15-puzzle, 24-puzzle)

### Water Jug Implementation
- DFS doesn't guarantee shortest solution
- No pre-check for mathematical solvability
- Prints all explored states (can be verbose)

 

GitHub: [https://github.com/kaushalkumar94/AI-labs/tree/main/lab1](https://github.com/kaushalkumar94/AI-labs/tree/main/lab1)
