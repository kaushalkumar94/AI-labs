# Tic-Tac-Toe with Alpha-Beta Pruning

##  Problem Statement
Tic-Tac-Toe is a classic two-player game played on a 3x3 grid. Each player takes turns marking a cell with their symbol (X or O). The objective is to place three of your marks in a row (horizontally, vertically, or diagonally) before your opponent does.  

The challenge is to design an **AI player** that plays optimally and never loses. A brute-force **Minimax algorithm** can achieve this but is computationally expensive as it explores the entire game tree. To optimize performance, we use **Alpha-Beta Pruning**, which reduces the number of game states that need to be evaluated.

---

##  Approach

### 1. **Game Representation**
- The board is represented as a list of 9 cells (`0–8`).
- Winning conditions are defined as sets of indices representing rows, columns, and diagonals.
- The evaluation function assigns:
  - `+1` if AI (X) wins
  - `-1` if Human (O) wins
  - `0` if draw

### 2. **Minimax Algorithm**
- Recursively simulates all possible moves.
- Maximizer (AI as X) tries to maximize the score.
- Minimizer (Human as O) tries to minimize the score.
- Base conditions:
  - Return `+1` if X wins.
  - Return `-1` if O wins.
  - Return `0` if no moves left (draw).

### 3. **Alpha-Beta Pruning**
- Introduces two parameters:  
  - **Alpha** → best score the maximizer (X) can guarantee so far.  
  - **Beta** → best score the minimizer (O) can guarantee so far.  
- During search:
  - Update `alpha` when finding a better option for maximizer.
  - Update `beta` when finding a better option for minimizer.
  - If `alpha >= beta`, further exploration of that branch is **pruned** (skipped) since it cannot affect the final decision.

### 4. **Gameplay**
- The human plays as **O**.
- The AI plays as **X** and always chooses the best move using Minimax with Alpha-Beta pruning.
- The game continues until a win or draw.

---

##  Time and Space Complexity

- **Time Complexity**:
  - Worst case: \(O(b^d)\), where `b` = branching factor (≈9), `d` = depth (9).
  - Best case with perfect pruning: \(O(b^{d/2})\).
  - For Tic-Tac-Toe: From ~387M possible states to ~20K states.

- **Space Complexity**:
  - \(O(d)\), where `d` = max depth of recursion (9).
  - Practically constant for Tic-Tac-Toe.

---


# AO* Algorithm

## Overview
The AO* (And-Or Star) algorithm is a graph search algorithm used in Artificial Intelligence to find the optimal solution in **AND-OR graphs**.  
Unlike A*, which finds the shortest path in a graph, AO* deals with problems where nodes can be decomposed into **subproblems**.  
- **OR nodes**: represent alternative choices (like A* branching).  
- **AND nodes**: represent decomposed subproblems that must all be solved together.  

AO* ensures that the selected solution subgraph has the **minimum cost** by updating estimates (backtracking) until convergence.

---

## Working Steps
1. Start from the root node.  
2. Expand nodes based on heuristics.  
3. Distinguish between **AND** and **OR** edges.  
4. Propagate costs backward to update parents.  
5. Select the partial solution graph with minimum cost.  
6. Continue until the root node is marked solved.  

---

## Complexity
- **Time Complexity**:  
  - Worst case: `O(b^d)` (exponential), where `b` is the branching factor and `d` is the solution depth.  
  - Depends on the heuristic quality—good heuristics reduce time drastically.  
- **Space Complexity**:  
  - `O(b*d)` for storing the graph and recursive calls.  
  - Similar to A*, AO* maintains explored nodes in memory.  

---

## Applications
- Problem solving with decomposition (planning, decision making).  
- Expert systems and diagnostic reasoning.  
- Game trees where AND/OR conditions exist.  

---
