# Fractional Knapsack (Greedy)

## CONCEPT
- Logic: Since you can break items, you should always be "greedy." Pick the item that is most expensive per kg (Value / Weight ratio). Keep picking the best ratio until the bag is full.

## ALGORITHM
- Calculate ratio = value / weight for every item.
- Sort all items in descending order of this ratio.

- Loop through sorted items:
1. If the item fits completely: Take it, subtract its weight from capacity.
2. If the item doesn't fit: Take the remaining capacity fraction (current_capacity / item_weight) * item_value and stop.


# Prim’s Algorithm (Graph - MST)
## CONCEPT
- Goal: Find the Minimum Spanning Tree (MST). This means connecting all nodes in the graph with the minimum total edge weight, without forming any loops (cycles).
- Start at Node 0.
- Put all neighbors in a "ToDo" list (Priority Queue) sorted by weight.
- Pick the smallest weight edge to a node you haven't visited yet.
- Repeat until all nodes are connected.
## ALGORITHM
1. Use a Min-Heap (Priority Queue) to store pairs: {weight, node}.
2. Create a visited array (all false initially).
3. Push {0, start_node} into the Heap.

Loop while Heap is not empty:
- Pop the element with the smallest weight.
- If the node is already visited, skip (continue).
- Else, mark it visited and add weight to sum.
- Push all non-visited neighbors of this node into the Heap.

# Dijkstra’s Algorithm (Graph - Shortest Path)

## CONCEPT
- Goal: Find the Shortest Path from a Source Node to ALL other nodes.
- Analogy: Think of Google Maps. You are at node 0. You want to know the quickest way to get to everyone else.

Difference from Prim's:
- Prim's: Cares about the edge weight only (just connect it!).
- Dijkstra: Cares about the Total Distance from Source (Path so far + new edge).
## ALGORITHM
1. Create a dist array. Set Source = 0, everyone else = Infinity.
2. Use a Min-Heap (Priority Queue). Push {0, start_node} (Distance, Node).
3. Loop while PQ is not empty:
- Pop the node with the shortest distance.
- Look at its neighbors.
- The "Relaxation" Step: If (dist[current] + edge_weight < dist[neighbor]):
- Update dist[neighbor] with the new smaller value.
- Push {new_dist, neighbor} to PQ.

# Kruskal’s Algorithm (Graph - MST)

## CONCEPT
- Goal: Find the Minimum Spanning Tree (MST) (Same goal as Prim's).
- Logic (The "Edge" Strategy): Unlike Prim's (which grows from a node), Kruskal's looks at the entire list of edges at once.

- Step 1: Sort all edges from smallest weight to largest.

- Step 2: Pick the smallest edge. Does it form a loop (cycle)?
- No? Add it to the tree.
- Yes? Discard it.
- Step 3: Repeat until all nodes are connected.

How to check for loops? We use a technique called Disjoint Set (Union-Find). If Node A and Node B already have the same "Parent" (leader), connecting them would form a loop.
## ALGORITHM

1. Store all edges in a list and Sort them by weight.
2. Create a parent array where every node is its own parent initially (parent[i] = i).

3. Loop through sorted edges:
- Find the "absolute parent" of u and v.
- If parent(u) != parent(v):
- Union: Connect them (make one the parent of the other).
- Add weight to result.
- Else: Skip (it forms a cycle).


# Bellman-Ford (Graph - Shortest Path)

## CONCEPT
- Goal: Shortest Path from Source to all nodes (Like Dijkstra).
- The Difference: Dijkstra fails if edges have Negative Weights (e.g., -5). Bellman-Ford handles them.
- Logic (The "Relax Repeatedly" Strategy):
- If you have V cities, the longest path without a loop can only have V-1 roads.
- So, if we relax ALL edges V-1 times, we are guaranteed to find the shortest path for everyone.
- Negative Cycle Detection: If we relax one more time (the $V^{th}$ time) and distances still get smaller, it means there is an infinite loop of negative weights (a trap).
## ALGORITHM
1. Initialize dist[] to Infinity, dist[src] = 0.

2. Loop V-1 times:
- Iterate through every edge (u, v, weight).
- Relax: If dist[u] != INF and dist[u] + w < dist[v], update dist[v].

- Check for Negative Cycles:
- Iterate edges one last time. If you can still update a distance, a negative cycle exists.

# Floyd-Warshall (Graph - All Pairs Shortest Path)

## CONCEPT
- Goal: Find the shortest path between EVERY pair of nodes (All-Pairs Shortest Path).

- The Logic (The "Via" Strategy):
- We want to go from City i to City j.
- We try going through an intermediate City k.
- Is i -> k -> j shorter than the direct i -> j?
- If yes, update the distance.
- We try this for every possible intermediate city k.
## ALGORITHM
1. Initialize a 2D matrix dist[V][V].
- dist[i][i] = 0 (Distance to self is 0).
- dist[i][j] = weight if edge exists.
- dist[i][j] = Infinity if no edge exists.

2. 3 Nested Loops:
- Loop k from 0 to V (The intermediate node).
- Loop i from 0 to V (The source).
- Loop j from 0 to V (The destination).
- Formula: matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]).

# Longest Common Subsequence (LCS) (DP)

## CONCEPT

## ALGORITHM


# Matrix Chain Multiplication (MCM) (DP)

## CONCEPT

## ALGORITHM


# Optimal Binary Search Tree (OBST) (DP)

## CONCEPT

## ALGORITHM


# Huffman Coding (Greedy)

## CONCEPT

## ALGORITHM


# String Matching (Naive/Brute Force)
## CONCEPT

## ALGORITHM

