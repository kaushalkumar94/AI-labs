class Graph:
    def __init__(self, graph, heuristic, start_node):
        self.graph = graph  # AND-OR graph structure
        self.H = heuristic  # Heuristic values
        self.start = start_node  # Start node
        self.solution_graph = {}  # Stores the final solution graph

    # Function to get neighbors (children)
    def get_neighbors(self, node):
        return self.graph.get(node, [])

    # Minimum cost child for OR nodes, or total cost for AND nodes
    def compute_cost(self, node):
        if node not in self.graph:
            return self.H[node]

        min_cost = float('inf')
        best_child = None

        for child_group in self.graph[node]:  # child_group is a list (AND set or single OR)
            cost = 0
            for child in child_group:
                cost += self.H[child]
            if cost < min_cost:
                min_cost = cost
                best_child = child_group

        self.H[node] = min_cost
        return best_child

    # Recursive AO* algorithm
    def AOstar(self, node):
        print(f"Expanding Node: {node}")
        if node not in self.graph:
            return

        best_child = self.compute_cost(node)
        self.solution_graph[node] = best_child

        for child in best_child:
            self.AOstar(child)  # recursive call

    def get_solution(self):
        return self.solution_graph


# Example Graph
graph = {
    'A': [['B', 'C'], ['D']],  # A → OR (choose B+C (AND) OR D)
    'B': [['E'], ['F']],  # B → OR (E OR F)
    'C': [['G']],  # C → OR (G only)
    'D': [['H', 'I']],  # D → AND (H and I both)
}

# Heuristic values (estimated costs)
heuristic = {
    'A': 10,
    'B': 6,
    'C': 4,
    'D': 8,
    'E': 2,
    'F': 4,
    'G': 3,
    'H': 1,
    'I': 2
}

# Run AO*
ao = Graph(graph, heuristic, 'A')
ao.AOstar('A')
solution = ao.get_solution()

print("\nFinal Solution Graph:")
print(solution)
