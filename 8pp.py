from copy import copy, deepcopy

# Initial and Goal States
ini_state = [[1, 3, 6], [8, 0, 4], [5, 2, 7]]
goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

# State class for BFS
class State:
    def __init__(self, tile_loc, par):
        self.tile_loc = tile_loc
        self.parent = par

    def getChildren(self):
        children = []
        r, c = self.getZeroLoc()
        new_zero_locs = [(r+1, c),(r, c+1), (r-1, c), (r, c-1)]  # Down, Right, Up, Left
        for new_loc in new_zero_locs:
            if self.isValid(new_loc):
                rn, cn = new_loc
                new_tiles = deepcopy(self.tile_loc)
                new_tiles[r][c] = self.tile_loc[rn][cn]
                new_tiles[rn][cn] = 0
                child = State(new_tiles, self)
                children.append(child)
        return children

    def getZeroLoc(self):
        for i in range(3):
            for j in range(3):
                if self.tile_loc[i][j] == 0:
                    return i, j

    def isValid(self, new_loc):
        ri, ci = new_loc
        return 0 <= ri < 3 and 0 <= ci < 3

    def printState(self):
        for i in range(3):
            for j in range(3):
                if self.tile_loc[i][j] != 0:
                    print(self.tile_loc[i][j], end=" ")
                else:
                    print("_", end=" ")
            print()

# Helper functions
color = {}

def getStrIdentity(tile_loc):
    return ''.join(str(tile_loc[i][j]) for i in range(3) for j in range(3))

def getColor(st):
    if st in color:
        return color[st]
    else:
        color[st] = "white"
        return color[st]

def setColor(st, newC):
    color[st] = newC

def goal_test(tile_loc):
    return getStrIdentity(tile_loc) == getStrIdentity(goal_state)

# BFS Function
def bfs():
    while queue:
        curr = queue.pop(0)
        if goal_test(curr.tile_loc):
            return curr
        setColor(getStrIdentity(curr.tile_loc), "black")
        children = curr.getChildren()
        for child in children:
            if getColor(getStrIdentity(child.tile_loc)) == "white":
                queue.append(child)
                setColor(getStrIdentity(child.tile_loc), "grey")
    return None

# Start BFS
queue = []
initial_state = State(ini_state, None)
queue.append(initial_state)
setColor(getStrIdentity(initial_state.tile_loc), "gray")
goal = bfs()

# Print final state and path
if goal:
    goal.printState()

    def printPath(node, movecount):
        mv = -1
        if node.parent:
            mv = printPath(node.parent, movecount)
        node.printState()
        print()
        return 1 + mv

    movecount = printPath(goal, 0)
    print("Moves needed: {}".format(movecount))
else:
    print("Goal state not reachable.")
