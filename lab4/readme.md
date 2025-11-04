# Tic-Tac-Toe using Minimax Algorithm

A C++ implementation of Tic-Tac-Toe game with an unbeatable AI opponent using the Minimax algorithm with game theory principles.

## Overview

This program implements a classic Tic-Tac-Toe game where a human player competes against an AI. The AI uses the Minimax algorithm to make optimal decisions, making it impossible to beat (you can only draw or lose). The implementation demonstrates adversarial search and game-playing strategies in artificial intelligence.

## The Tic-Tac-Toe Game

Tic-Tac-Toe is a two-player game played on a 3×3 grid where:
- Players take turns marking spaces
- One player uses 'X' (AI), the other uses 'O' (Human)
- The first player to get three marks in a row (horizontal, vertical, or diagonal) wins
- If all 9 spaces are filled without a winner, the game is a draw

**Example Game Board:**
```
X . O
. X .
O . X
```

## Problem Statement

**Given:**
- A 3×3 game board with current game state
- Two players: MAX (AI using 'X') and MIN (Human using 'O')
- Turn-based gameplay

**Find:**
- The optimal move for the AI that maximizes its chance of winning
- Guarantee that AI never loses (can only win or draw)

**Goal:**
- MAX (AI) tries to maximize the score (+1 for AI win)
- MIN (Human) tries to minimize the score (-1 for Human win)
- 0 represents a draw

## The Minimax Algorithm

Minimax is a decision-making algorithm for two-player zero-sum games that assumes both players play optimally.

### Core Concept

**MAX Player (AI):**
- Chooses the move that maximizes the minimum score
- Assumes opponent will play optimally to minimize AI's score

**MIN Player (Human):**
- Chooses the move that minimizes the maximum score
- Assumes AI will play optimally to maximize its score

### Algorithm Steps

1. **Evaluate Terminal States:**
   - If AI wins: return +1
   - If Human wins: return -1
   - If draw (no moves left): return 0

2. **MAX's Turn (AI):**
   - Try all possible moves
   - For each move, recursively call minimax for MIN's turn
   - Choose the move with maximum value
   - Return the best value

3. **MIN's Turn (Human):**
   - Try all possible moves
   - For each move, recursively call minimax for MAX's turn
   - Choose the move with minimum value
   - Return the best value

4. **Best Move Selection:**
   - For each empty cell, simulate AI's move
   - Calculate minimax value assuming optimal opponent play
   - Select the move with highest value

## How the Code Works

### Key Components
```cpp
const int PLAYER = -1;  // Human (MIN player)
const int AI = 1;       // Computer (MAX player)

struct Move {
    int row, col;       // Position on the board
};
```

### Main Functions

**`evaluate(board)`** - Checks for winner
- Returns +1 if AI wins (three X's in a row)
- Returns -1 if Human wins (three O's in a row)
- Returns 0 if no winner yet

**`minimax(board, isMax)`** - Recursive minimax algorithm
- Explores all possible game states
- Returns best achievable score for current player
- Assumes both players play optimally

**`findBestMove(board)`** - Finds optimal move for AI
- Tries all empty positions
- Evaluates each move using minimax
- Returns position with highest score

**`movesLeft(board)`** - Checks if game can continue
- Returns true if empty cells exist
- Returns false if board is full

### Game Flow

1. Display empty board
2. **Human's turn:**
   - Input row and column (0-2)
   - Validate move (cell must be empty)
   - Place 'O' on board
   - Check for human win or draw
3. **AI's turn:**
   - Calculate best move using minimax
   - Place 'X' on board
   - Display AI's choice
   - Check for AI win or draw
4. Repeat until game ends

## Complexity Analysis

### Time Complexity: **O(b^m)**

Where:
- **b** = branching factor (average number of legal moves per state)
- **m** = maximum depth of game tree (9 for Tic-Tac-Toe)

**Detailed Analysis:**
- First move: 9 possible positions
- Second move: 8 possible positions
- Third move: 7 possible positions
- ...and so on

Total game tree nodes ≈ 9! = 362,880 in worst case

However, with pruning and early termination:
- Typical nodes explored: ~10,000 - 50,000
- Actual complexity: **O(9!) ≈ O(362,880)** worst case
- Practical: Much faster due to terminal state detection

### Space Complexity: **O(m)**

Where:
- **m** = maximum depth of recursion (9 moves maximum)

**Space Usage:**
- **Recursion stack** - O(m) = O(9) for call stack
- **Board state** - O(1) since board is 3×3 = constant
- **Total space** - O(m) = **O(9)** which is effectively **O(1)**

The space complexity is linear in the depth of the game tree, but since Tic-Tac-Toe has a maximum of 9 moves, this is bounded by a small constant.

## Compilation and Execution

### Prerequisites
- C++ compiler supporting C++11 or higher

### Compile and Run
```bash
g++ -std=c++11 tictactoe_minimax.cpp -o tictactoe
./tictactoe
```

## Usage Example
```
Tic Tac Toe (AI = X, Human = O)

. . .
. . .
. . .

Enter your move (row col): 0 0

O . .
. . .
. . .

AI chooses: 1 1

O . .
. X .
. . .

Enter your move (row col): 0 1

O O .
. X .
. . .

AI chooses: 0 2

O O X
. X .
. . .

Enter your move (row col): 2 0

O O X
. X .
O . .

AI chooses: 1 0

O O X
X X .
O . .

Enter your move (row col): 1 2

O O X
X X O
O . .

AI chooses: 2 1

O O X
X X O
O X .

Enter your move (row col): 2 2

O O X
X X O
O X O

It's a draw!
```

## Input Format

- Enter row and column as two space-separated integers (0-2)
- Example: `1 1` places your mark in the center
- Board positions:
```
(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2)
(2,0) (2,1) (2,2)
```

## Key Features

- **Unbeatable AI** - Uses optimal strategy, never loses
- **Interactive Gameplay** - Human vs Computer
- **Board Visualization** - Clear display of current state
- **Move Validation** - Prevents invalid moves
- **Win Detection** - Checks rows, columns, and diagonals
- **Draw Detection** - Identifies when board is full

## Minimax Properties

### Advantages
- **Optimal Play** - Always finds the best move
- **Complete** - Explores entire game tree
- **Guaranteed Results** - AI cannot lose
- **Simple Logic** - Easy to understand and implement

### Limitations
- **Exponential Time** - Impractical for complex games
- **No Pruning** - Explores all branches (can be optimized with Alpha-Beta)
- **Memory Usage** - Recursion depth can be large for bigger games
- **Deterministic** - Always plays the same way for same position

## Game Theory Concepts

**Zero-Sum Game:**
- One player's gain = other player's loss
- Total utility always sums to zero
- Perfect for minimax approach

**Perfect Information:**
- Both players see entire game state
- No hidden information or randomness
- Makes minimax applicable

**Optimal Strategy:**
- AI plays perfectly using game tree search
- Assumes opponent also plays perfectly
- Results in draw when both play optimally

## Possible Improvements

1. **Alpha-Beta Pruning** - Reduce number of nodes evaluated (significant speedup)
2. **Move Ordering** - Evaluate better moves first for faster pruning
3. **Transposition Table** - Cache repeated board positions
4. **Iterative Deepening** - For depth-limited search
5. **Difficulty Levels** - Add random moves for easier AI
6. **Opening Book** - Pre-computed optimal first moves
7. **GUI Interface** - Graphical board display
8. **Two-Player Mode** - Human vs Human option

## Alpha-Beta Pruning

The current implementation can be optimized using Alpha-Beta pruning, which eliminates branches that cannot affect the final decision:

- **Alpha** - Best value MAX can guarantee
- **Beta** - Best value MIN can guarantee
- Prune when Beta ≤ Alpha

This can reduce time complexity from O(b^m) to O(b^(m/2)) in best case.

## Mathematical Analysis

**Game Tree Size:**
- Nodes at depth 0: 1
- Nodes at depth 1: 9
- Nodes at depth 2: 9 × 8 = 72
- Total nodes ≈ 9! = 362,880

**Optimal Play Result:**
- When both players play perfectly: Draw
- AI never loses against optimal opponent
- AI wins against non-optimal play
 
