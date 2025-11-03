# Blocks World Goal Stack Planner

A Python implementation of the **Goal Stack Planning** algorithm for solving the classic **Blocks World Problem** in Artificial Intelligence.

## Overview

This project implements a **Goal Stack Planner** that solves planning problems in the Blocks World domain. The planner uses backward chaining from the goal state to find a sequence of operations that transforms an initial state into a desired goal state.

## The Blocks World Problem

The Blocks World is a classic planning domain in AI consisting of:
- **Blocks** (labeled A, B, C, etc.) that can be stacked on top of each other
- A **table** where blocks can be placed
- A **robotic arm** that can manipulate one block at a time

### Predicates

The world state is described using five predicates:

- `ON(X, Y)` - Block X is on top of block Y
- `ONTABLE(X)` - Block X is on the table
- `CLEAR(X)` - Block X has no blocks on top of it
- `HOLDING(X)` - The arm is holding block X
- `ARMEMPTY()` - The arm is not holding any block

### Operations

Four operations can manipulate the blocks:

- `STACK(X, Y)` - Place block X (currently held) onto block Y
  - *Preconditions:* CLEAR(Y), HOLDING(X)
  - *Effects:* ARMEMPTY(), ON(X,Y)
  
- `UNSTACK(X, Y)` - Pick up block X from on top of block Y
  - *Preconditions:* ARMEMPTY(), ON(X,Y), CLEAR(X)
  - *Effects:* CLEAR(Y), HOLDING(X)
  
- `PICKUP(X)` - Pick up block X from the table
  - *Preconditions:* CLEAR(X), ONTABLE(X), ARMEMPTY()
  - *Effects:* HOLDING(X)
  
- `PUTDOWN(X)` - Place the held block X on the table
  - *Preconditions:* HOLDING(X)
  - *Effects:* ARMEMPTY(), ONTABLE(X)

## Problem Statement

**Given:**
- An **initial state** describing the current configuration of blocks
- A **goal state** describing the desired configuration of blocks

**Find:**
- A sequence of operations that transforms the initial state into the goal state

**Example Problem:**

*Initial State:*
```
    B
    A    C    D
  ---------------
      Table
```
Represented as: `[ON('B','A'), ONTABLE('A'), ONTABLE('C'), ONTABLE('D'), CLEAR('B'), CLEAR('C'), CLEAR('D'), ARMEMPTY()]`

*Goal State:*
```
    B    C
    D    A
  ---------------
      Table
```
Represented as: `[ON('B','D'), ON('C','A'), ONTABLE('D'), ONTABLE('A'), CLEAR('B'), CLEAR('C'), ARMEMPTY()]`

## How the Algorithm Works

The **Goal Stack Planning** algorithm uses backward chaining to find a solution:

1. **Initialize** a stack with the goal state as a compound goal
2. **While the stack is not empty:**
   - If the top is a **compound goal** (list), pop it and push all unsatisfied sub-goals onto the stack
   - If the top is an **operation**, check if all preconditions are satisfied:
     - If preconditions are unsatisfied, push them onto the stack
     - If all preconditions are satisfied, execute the operation (update world state) and add to solution plan
   - If the top is a **satisfied goal** (already in world state), pop it from the stack
   - If the top is an **unsatisfied goal**, replace it with an operation that can achieve it and push the operation's preconditions onto the stack
3. **Return** the sequence of operations as the solution plan

## Complexity Analysis

### Time Complexity: **O(n × m × p)**

Where:
- **n** = number of goals in the goal state
- **m** = maximum depth of the goal stack
- **p** = average number of predicates checked per operation

The algorithm performs goal decomposition and checks preconditions for each operation. In typical blocks world scenarios, the time complexity is polynomial. However, in worst-case scenarios with complex goal dependencies, the algorithm may exhibit exponential behavior due to potential backtracking and goal interactions.

### Space Complexity: **O(n + m + s)**

Where:
- **n** = number of predicates in the world state (typically 3-5 per block)
- **m** = maximum depth of the goal stack (proportional to plan length)
- **s** = number of steps in the solution plan

The space is dominated by:
- **World state representation** - List of predicates describing current configuration
- **Program stack** - For managing goals, subgoals, and operations
- **Solution steps list** - Final sequence of operations

For a problem with k blocks, the space complexity is approximately **O(k)** since the world state contains O(k) predicates and the stack depth is bounded by the number of operations needed.

## Usage

```python
from goal_stack_planner import *

# Define initial state
initial_state = [
    ON('B','A'),
    ONTABLE('A'), ONTABLE('C'), ONTABLE('D'),
    CLEAR('B'), CLEAR('C'), CLEAR('D'),
    ARMEMPTY()
]

# Define goal state
goal_state = [  
    ON('B','D'), ON('C','A'),
    ONTABLE('D'), ONTABLE('A'),
    CLEAR('B'), CLEAR('C'),
    ARMEMPTY()
]

# Create planner and get solution
planner = GoalStackPlanner(initial_state, goal_state)
steps = planner.get_steps()

# Print solution
print("Solution Plan:")
for i, step in enumerate(steps, 1):
    print(f"{i}. {step}")
```

## Example Output

Running the code with the example problem produces:

```
Solution Plan:
1. UNSTACK(B,A)
2. PUTDOWN(B)
3. PICKUP(C)
4. STACK(C,A)
5. PICKUP(B)
6. STACK(B,D)
```

This sequence of 6 operations successfully transforms the initial configuration into the goal configuration.

## Implementation Features

- **Object-oriented design** with base classes for predicates and operations
- **Automatic action selection** - Each predicate knows which operation can achieve it
- **Precondition checking** - Operations verify prerequisites before execution
- **World state management** - Automatic updates using add/delete lists
- **Extensible architecture** - Easy to add new predicates or operations

## Limitations

- Assumes deterministic actions (operations always succeed)
- Does not optimize for plan length (may not find the shortest plan)
- Cannot handle the **Sussman Anomaly** and complex goal interactions where naive goal ordering fails
- No support for resource constraints or parallel actions
- Limited to the blocks world domain (not a general-purpose planner)

## References

- STRIPS Planning System (Stanford Research Institute Problem Solver)
- Russell & Norvig - Artificial Intelligence: A Modern Approach
- Classical AI Planning literature
