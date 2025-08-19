# AI Problems and Algorithms

This repository contains implementations of classic AI problems and algorithms. Each problem includes a description, the algorithm used, and its time and space complexity.
 

## 1. 8-Puzzle Problem (Hill Climbing with Heuristic)

### Problem Statement
The 8-puzzle problem consists of a 3x3 board with tiles numbered from 1 to 8 and one empty space. The goal is to move the tiles to reach the final configuration (goal state) using valid moves (up, down, left, right).

### Algorithm
- Represent the puzzle state as a 3x3 matrix.
- Define a heuristic function (such as misplaced tiles or Manhattan distance).
- Start from an initial state and repeatedly move to a neighboring state with a better heuristic value.
- Continue until the goal state is reached or no better neighbor exists.

### Complexity
- **Time Complexity:** Exponential in the worst case, but depends on the heuristic function.
- **Space Complexity:** O(b^d), where `b` is the branching factor and `d` is the depth.

 

## 2. Water Jug Problem (DFS State-Space Search)

### Problem Statement
Given two jugs with capacities `m` and `n` liters and an unlimited water supply, measure exactly `d` liters. Operations allowed are filling a jug, emptying a jug, and pouring water between jugs.

### Algorithm
- Represent each state as `(x, y)` where `x` is the water in jug1 and `y` is the water in jug2.
- Start with `(0, 0)`.
- Generate new states by:
  - Filling jug1 or jug2
  - Emptying jug1 or jug2
  - Pouring water from one jug to another
- Use DFS with a visited set to avoid repetitions.
- Stop when either jug has the target amount.

### Complexity
- **Time Complexity:** O(m * n)
- **Space Complexity:** O(m * n)
 

## 3. Magic Square Problem

### Problem Statement
A magic square of order `n` is an arrangement of numbers from `1` to `n^2` in an `n x n` matrix such that the sum of each row, column, and diagonal is the same.

### Algorithm (Siamese Method for odd n)
- Start by placing `1` in the middle of the top row.
- The next number is placed one row up and one column right (wrapping around).
- If the cell is already filled or out of bounds, place the number directly below the previous number.
- Continue until all numbers are placed.

### Complexity
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n^2) for storing the matrix

 

## 4. Tic Tac Toe Game

### Problem Statement
Tic Tac Toe is a two-player game played on a 3x3 grid. Players take turns marking a cell with `X` or `O`. The player who places three of their marks in a row, column, or diagonal wins. If all cells are filled and no player has won, the game ends in a draw.

### Algorithm (Minimax for AI)
- Represent the game as a 3x3 board.
- At each turn:
  - The AI evaluates all possible moves using the minimax algorithm.
  - It chooses the move that maximizes its chances of winning while minimizing the opponent's chances.
- The game continues until there is a win or draw.

### Complexity
- **Time Complexity:** O(b^m), where `b = 9` (possible moves at start) and `m` is depth of the game tree.
- **Space Complexity:** O(b * m) due to recursion stack.

 AUTHOR Kaushal Kumar
