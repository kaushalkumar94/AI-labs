
********# 8-Puzzle Problem Solver using BFS (Breadth-First Search)

This project implements a solution to the **8-puzzle problem** using the **Breadth-First Search (BFS)** algorithm in Python. The program searches for the shortest path to reach the goal configuration from a given starting state.

 

##  What is the 8-Puzzle Problem?

The 8-puzzle consists of a 3x3 grid containing 8 numbered tiles and one blank space (represented by 0). The goal is to move the tiles around until they are in a specific final configuration using valid moves (up, down, left, right).

###  Valid Moves:
- You can slide a tile into the blank space (0)
- Only adjacent tiles to 0 can move

###  Goal State:
By default, the goal state is:
```
1 2 3
4 5 6
7 8 0
```

 

##  Algorithm Used: Breadth-First Search (BFS)

**BFS** is used to explore the shortest sequence of valid moves to reach the goal state from the initial configuration.

- It explores all nodes level by level
- Uses a **queue** to manage states
- Ensures **shortest path** to solution
- Uses **coloring** (`white`, `gray`, `black`) to track visited states

 

##  How It Works

1. Input an initial puzzle configuration (e.g., `[[1, 3, 6], [8, 0, 4], [5, 2, 7]]`)
2. Define the goal state (default is `[[1,2,3],[4,5,6],[7,8,0]]`)
3. Each state is represented as a `State` object, holding:
   - Current tile configuration
   - Reference to its parent (for tracing the solution path)
4. The program performs BFS to explore the state space
5. If goal state is found:
   - It prints the path from start to goal
   - Displays the number of moves required
##  Author

[Kaushal Kumar] 

