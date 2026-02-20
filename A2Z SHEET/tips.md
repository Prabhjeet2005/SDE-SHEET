# KEYWORDS For Revise.md:

- EDGE CASE -> Cases that i missed or can miss
- FORMULA -> Formula For Particular question
- NON INTUITIVE -> No intuition almost WROTE Learning
- CONCEPT -> Makes Many Question Clear

# Custom Data Structure
Suppose we need to return for a function 
```
<int,bool,string,double>
```
the we can Make a struct
```
struct Example{
  int height;
  bool is_balanced;
  string name;
  double ans;
};

Example eg_function(){
  Example eg1 = eg_function()
  Example eg2 = eg_function()
  Example eg3 = {20,true,"eg",2.3};
  int new_height = eg1.height + eg2.height;
  return {new_height,eg1.is_balanced,eg2.name,eg2.ans};
}
```


# Array Declaration

- int arr[25] = {0};
- STL Sort Override
- std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // For descending order, we want 'a' to come before 'b' if a.score is greater.
        return a > b;
  });

# Custom Array SORT Declaration
- IMPORTANT: it must be statically declared
```
bool static custom_compare(int &a,int &b){
  return a<b;
}

sort(arr.begin(),arr.end(),custom_compare)
```


## SLIDING WINDOW
- Always if all +ve elements

# MIN HEAP OVERRIDE Custom Operator
Heap -> Max By default
```
MIN HEAP
struct CustomCompare{
  bool operator()(Node* a,Node* b){
    return a->val > b->val;
  }
}
```
// Think of giving priority Question HEap asks is (a,b) out of a and b; is a smaller than b if so then enter into maxHeap b
// TRUE -> Take b, FALSE Take a
// Heap Asks if a->val smaller than b->val as by default it is maxHeap expects greater first
// Eg: a=3, b=5 ; 3 > 5 -> False

# Duplicates -> _XOR_

# Subarray/Array Sum -> [PREFIX SUM] _HashMap_ => store sum or element & indexes

- Map Should Be Used For **_LONGEST_**
- ![alt text](images/diagram-export-8-21-2025-11_00_47-PM.svg)

# 2sum/3sum/4sum

- Target - arr[i] or Target - arr[i] + arr[j] or Target - arr[i] + arr[j] + arr[k] then lookup this element in stored set to get other element in O(n) => Better Appproach
- Sort Array & Search Greedily => OPtimized Approach

# [1,n] given think of calculating sum or making 2 equatins of SumN and Sum^2N and solving them

# Count Inversions/Reverse _PAIRS_ (i < j && arr[i]>arr[j]) => Merge Sort

- pairs try to use merge sort if i < j && arr[i] > arr[j] something like this condition

# Binary Search

- **_Binary Search on 1D_** Use Some Trick to Move in Either of Half (Recognize some pattern)
- **_ANSWER SPACE: _** For Finding Min/Max, Find Min Value, Max Value and apply Binary Search While looping from min <= max look if each possible otherwise go to other half
- One Limit to Another Limit Consecutive Try Apply Binary Search Eg. [minElement,maxElement] or [1,n]
- [No,No,No,Yes,Yes,Yes,Yes] -> Ans Search Space Array Looks Something like this find the min or max

## **_Binary Search [Book Allocate, Aggressive Cows, Painter Partition]_**

- greedily take sum and increase count if limit violated

## Binary Search [Decimal] Method

- ![alt text](images/diagram-export-9-8-2025-8_41_01-AM.svg)
- For First 6 Decimal Places Matching
- while(high - low > 1e-6) low = mid , high = mid

# Binary Search V/s DP

- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.11 AM.png>)
- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.46 AM.png>)

# Binary Search Partition

- 2 Array Given assume a partition and decide how many elements to take from smaller size array

# Maths

## LCM

- LCM = |a| \* |b| / GCD(a,b) => Avoid Integer Overflow Multiply |b| seperate
- **_GCD Formula_**
- ![alt text](images/diagram-export-9-9-2025-7_27_35-PM.svg)

## Odd/Even Trick

- Odd + Even -> Odd
- Even + Odd -> Odd
- Odd + Odd -> Even
- Even + Even -> Even

## >> , <<

- \>\> this operator divides number with 2^n [40 \>\> 2 will be 40 / 2^2]
- << this operator multiplies number with 2^n [5 << 3 will be 5 * 2^3]

## Find Ceil

- ceil( (double)arr[i] / (double) i ) // DOUBLE is Important otherwise give floor value

# REVERSAL

- Try To Use Stack If Removal of something or reversing

# Strings


## STRING STL

- .size(), .empty(), str[0], .front(), .back()
- += best for appending a string to another string
- .push_back() -> Adds Only 1 char, .insert(index,"string")
- .erase(index,length), .clear()
- str.find("any_string") != string::npos -> return index, .substr(index,len)

### string::npos is constant representing "not found" 
- to_string(42), stoi("42"), stod("4.2")

### String Extract Numbers
- ***EG: "2245 23 45 6 33"***
- From this extract numbers like 2245, 23, 45, 6 ,33
```
METHOD 1. [EASIEST BUT INTERVIEWER AVOID THIS METHOD]
#include<sstream>
string str = "2245 23 45 6 33"
stringstream stream_name(str);
int num;
while(stream_name >> num){
  cout << num;
}
```
```
METHOD 2.
string str = "2234 23 5  77 90 45";
  str+=' ';
  int curr_num = 0;
  bool first_space = false;

  for(auto &ch: str){
    if(ch == ' '){
      if(first_space){ // Avoid 0 output on Double Space
        cout<<curr_num<<"\n";
        first_space = false;
        curr_num = 0;
      }
    }else{
      curr_num = (curr_num*10) + (ch-'0');
      first_space = true;
    }
  }
```

# Linked List [Think in Edge Cases]
- Use Class for using OOPS concepts
- template can be used here
- For Insertion/Deletion at position or value Always take 2 nodes curr & prev
- DELETION delete ptr_name OR free(ptr_name) ===> Free Up The space IMPORTANT

## Fast & Slow Pointer/ Hare & Tortoise Method
- slow -> 1, fast move 2
- DETECT LOOP, FIND MIDDLE

# Heap [Priority Queue]

- When Repeatedly find max or min and array constatntly Change then use HEAP


# Stacks & Queues
## STACKS [When Use]
- LIFO(Reverse Order Processing)
- Match Open/Close Symbols
- Backtracking(DFS,Postfix)
- Simulate Recursion Call Stack,
- MONOTONIC STACK->Stack maintain same order like always increase or always decrease(Find prev/next/smaller/greater elements)[Eg: Daily Temperature, Largest Rectangle in Histogram]
- IMPORTANT:  Deal with Most Recent Info like closing Bracket

# BITMASK
## When to use BITMASK?
1. "Is N very small (<= 20)?" -> Think Bitmask DP (Toolbox #1 & #4). 
2. "Does it involve finding a unique element?" -> Think XOR (Toolbox #3).
3. "Is it about binary strings or bits?" -> Think Set/Clear/Check (The whole toolbox).
- **What 1 << k does?[0-BASED INDEXING]** 
- 1 << k create number with only K turned on eg 1<<2 creates 000100 
## 1. The "Set Bit" Operation (Turn a switch ON)
- Goal: Force the $k$-th bit to become 1.
- ```Formula: num = num | (1 << k)```  <-- This is your Gray Code formula!
- Logic:1 << k: Creates a "mask" with a single 1 at position k. (e.g., 00100)| (OR): If either bit is 1, the result is 1.
- Result: It keeps all original bits, but forces the $k$-th bit to 1.
## 2. The "Clear Bit" Operation (Turn a switch OFF)
- ~ means NOT
- Goal: Force the $k$-th bit to become 0.
- Formula: ```num = num & ~(1 << k)```
- Logic:~(1 << k): Creates a mask where position k is 0 and everything else is 1. (e.g., 11011)& (AND): Only keeps a bit if both are 1.
- Result: Since the mask has a 0 at $k$, that bit gets wiped out. The 1s elsewhere preserve the original numbers.
## 3. The "Toggle Bit" Operation (Flip a switch)
- Goal: If it's 1, make it 0. If it's 0, make it 1.
- Formula: ```num = num ^ (1 << k)```
- Logic:^ (XOR): Returns 1 if bits are different.
- Result: 1 ^ 1 = 0 (flips to off), 0 ^ 1 = 1 (flips to on).
## 4. The "Check Bit" Operation (Is the switch ON?)
- Goal: True/False check.
- Formula: ```(num & (1 << k)) != 0```
- Logic:It masks out everything except the $k$-th bit. If the result is non-zero, that bit must have been ON.

# Recursion & Backtracking
## 1. The "Binary Choice" Pattern (Pick / Not Pick)
- Used For: ```Subsets, Combinations, generating subsequences.```
- The Logic: At each step, you make a Yes/No decision for the current element.
- Handling Duplicates (Subsets II):
Sort the array first. On the "Not Pick" branch, use a while loop to skip all identical next elements.

## 2. The "Iterative Choice" Pattern (Fill the Slots)
- Used For: ```Permutations, Combinations (alternative), N-Queens, Sudoku.```
- The Logic: You have a "slot" to fill. You iterate through all available candidates to put in that slot.
- Permutations vs. Combinations:
- Permutations (Order matters): Loop i starts from 0. Use a visited array.
- Combinations (Order doesn't matter): Loop i starts from index (forward only). No visited array needed.

- Handling Duplicates (Permutations II):
Sort array. Inside the loop: if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

## 3. The "Cutting" / Partitioning Pattern
- Used For: ```Palindrome Partitioning, Word Break, Restore IP Addresses.```
- The Logic: You are holding a knife at index. You try making a cut at every possible position i after it.
- Structure:

C++
``` 
for (int i = index; i < s.length(); i++) {
    // 1. Identify the 'chunk' or 'slice'
    string chunk = s.substr(index, i - index + 1);

    // 2. Validate the chunk
    if (isValid(chunk)) {
        // 3. Recurse on the REST of the string
        // NOTE: The rest starts at 'i + 1'
        solve(i + 1);
    }
}
```

## 4. The Grid Search Pattern (DFS on Matrix)
- Used For: ```Word Search, Rat in a Maze, Number of Islands, Max Gold.```
- The Logic: Explore paths on a 2D grid.

# Trees
## Perfect Binary Tree
```
Total Nodes in Perfect Binary Tree = (2^Height - 1)
Eg: Height = 3
2^3-1 ==> It will have 7 nodes
```

All internal Nodes have 2 children
## Complete Binary Tree
All internal nodes are present and all leaf nodes are close to left as possible
```
        1
       / \
      2   3
     /\   /
    4  5  6
```



## BST
### 1. Insertion
- Normal Insertion just use recursion and whenever nullptr node found insert it here and return this new_node

### 2. Searching
- use recursion and whenever element found print it

### 3. Deletion
- There can be 3 cases: 0 Child [LEAF NODE], 1 Child, 2 Child
1. **0 Child:** simply delete the node
2. **1 Child:** store the left or right child then delete root node and return stored_child_node
3. **2 Child:** Find **INORDER SUCCESSOR** (Right subtree smallest element) when found update root->value with inorder_successor->value then again use recursion on right subtree with element inorder_successor->value to automatically delete the Inorder Successor as it is no longer required

### 4. Print Level Order [Queue]
- Use Queue to store root then immediately push nullptr then 
- while(!queue.empty()) repeatidly get front of queue then 
- if front == nullptr [Level Ended] then if still queue has elements then add another nullptr 
- else print front->value and add left and right child to queue if they exist

### 5. Height Tree
```
int Height(Tree* root){
  if(root == nullptr)return 0;
  int left_height = Height(root->left);
  int right_height = Height(root->right);

  return 1 + max(left_height,right_height);
}
```

- Height V/S Depth
1. Height: How far from deepest leaf node
2. Depth: How far from root

### AVL V/S Red-Black Trees
1. AVL: (Strictly Balanced) ==> At Most 1 difference between Heights of Left and Right Subtree
2. Red-Black Trees: (Roughly Balanced) ==> ensure longest path no longer than twice shortest path

### LCA 
- If 2 Nodes then deepest nodes that is parent to both nodes

### Diameter of Tree
- Longest Path between 2 Nodes


# Graphs
## TOUGHEST TOPIC: BRIDGES[Tarjan's Algorithm]

## Graph representation
All Graph Questions Given 2 Things:-
1. N : No. of Nodes
2. edges : [[1,2],[2,4],[1,5]] All Connected edges

### Adjacency List
- Array where every index eg: index 0 represent a node and store a list of all nodes directly connected to Node 0 
```
vector<vector<int>> adj_list = { {1, 4} , {0, 2, 3} };
adj[0] = {1,4}
adj[1] = {0,2,3}
Means Nodes connected to 0 are 1,4 and Nodes connected to 1 are 0,2,3
```

### Undirected & Directed Graph Adjacency List Creation
### UNDIRECTED graph [Bi-directional Edge]
u <-> v
- adj[u].push_back(v)
- adj[v].push_back(u)

### DIRECTED graph 
u -> v
- adj[u].push_back(v)

### Weighted Graph {u,v,weight}
```
vector< vector< int >>edges = {{0, 1, 10}, {0, 4, 5}};
vector<vector<pair<int,int>>> adj_list
```
- adj_list[u].push_back({v,w})
- adj_list[v].push_back({u,w})

### Nodes Access in GRAPHS
- **TREE:** Use root->left, root->right
- **GRAPHS**
```
for(int neighbour: adj[current_node]){
  ...Do Something
}
```

### Visited Array Concept: ***MARK VISITED AS SOON AS WE SEE THE NODE, NOT WHILE POPPING BUT IT'S FIRST OCCURENCE***

### BFS V/s DFS Templates
#### Disconnected Graphs
For All Nodes Visit Run 
```
for(int i=0; i<n; i++){
  if(!visited[i]){
    bfs or dfs
  }
}
```

#### 1. BFS
Use Visited Array + Queue
- push first node from adj_list in queue
- pop from queue and do some operation & visit it's neighbours if not yet visited & mark it as visited

#### 2A. DFS [DEFAULT CALL STACK]
[DEFAULT WAY] Use Visited Array
- In DFS Helper
- Mark VISITED
- Process Node
- Recurse for neighbours

#### 2. DFS [Custom STACK]
Same As BFS instead of queue use a stack + VISITED

## Graph Algorithms
### 1. Kahn's Algorithm [Topological Sort] [Inorder == 0 & BFS]
- Concept: In-Degrees and Queues [Process Nodes with 0 Dependencies First]
- BFS Based
- Work Only on **DAG** [Directed Acyclic Graph]
- If Cycle Present, Topological Sort is Impossible
- USED FOR: 
1. Dependency Resolution (Course Schedule, Alien Dictionary)
2. Give Valid Sequence, Detects Cycle
- Eg: Build Order, Do "Intro To CS" before you can take "DSA" subject

#### ALGORITHM [Topo Sort [BFS BASED] [Indegree 0 First]]
1. Calculate All Nodes InDegree
2. Push Onto Queue All Nodes Indegree == 0
3. Do BFS, Process it and while traversing Neighbours indegree[neighbour]--, if indegree[neighbour]==0 then push it onto queue
4. if topo_vector.size() != N, then CYCLE PRESENT and return {}, otherwise return topo_vector

### 2. Union-Find [DSU] [IMPLEMENT WITH ANOTHER CLASS] [IMPORTANT]
- USED FOR: Grouping, Cycle Detection in Undirected Graph (Redundant Connections, Accounts Merge, Connected Components)
- Time Complexity: Naive O(N), But Optimized is O(1)

#### CYCLE DETECTION
If Edge already has same parents then there is cycle

#### 1. find(parent) [With Path Compression]
- O(1)
- Node 3 looks for its leader 3 -> 2 -> 1 -> Root
- Optimization: Make Node 3 Directly Point to Root, Next Lookup Instant

#### 2. union(u,v) [With Rank/Size Merge "Big <- Small" ]
- When Merging 2 Groups Always Attatch Shorter graph To Taller Graph

#### ALGORITHM [Initialize Array By N+1 to cover 1-Based Indexing]
- Initialize a parent array where every node its own parent initially
- Initialize a Rank Array with each Node's Rank as 0 [Rank To Determine which Tree Big]

1. find_parent(u)
- if(node == parent[node])then return node
- otherwise Path compress parent[node] = find_parent(parent[node])

2. union(u,v)
- First find parent_u & parent_v
- Same parent then Early Return
- 2 Cases:
- A. Ranks or Heights Unequal then attach smaller Rank to Bigger Rank, No change in Rank
- B. Ranks EQUAL then attach graph as both equal height and Rank of Leader + 1 because other graph of same height is attatched to leader which leads to total new height to be increased by 1

```
1. RANK UNEQUAL
Graph A (Rank 2)        Graph B (Rank 0)
      (A)                       (B)
      /
    (C)
    /
  (D)

Attatch B To A

      (A)  <-- Still Rank 2
      / \
    (C) (B) <-- B is just a new child, depth didn't exceed D's depth.
    /
  (D)
```
```
2. RANK EQUAL
Tree A (Rank 1)        Tree B (Rank 1)
      (A)                    (B)
       |                      |
      (C)                    (D)

Attatch B To A
      (A)   <-- Must increase to Rank 2!
      / \
    (C) (B)
         |
        (D) <-- Look! D is now 2 steps away. The tree got taller.
```


### 3. Dijkstra Algorithm [Shortest Path Weighted graph +ve weights, SOURCE TO EVERYWHERE]
- TC/SC: O(ElogV)/O(V)
- USED FOR: Shortest Path Weighted graph +ve weights
- DIRECTED + UNDIRECTED Graphs
- Concept: BFS + Min-Heap (Priority Queue). "Always expand the cheapest node next."
- Questions: Min time/ Min Cost

- NOTE: I use LAZY DIJKSTRA w/o visited array, So my code can actually calculate for -ve Edges as well, but too many -ve edge causes it TC to be Exponential, Also, it can't detect -ve CYCLE

#### Algorithm [BFS + Min Heap]
1. Initialize a dist array all Nodes INT_MAX, dist[source] = 0
2. Push into Priotity Queue [Min Heap] {node,weight}, initially push {0,weight}
3. Visit the neighbours of pq.top() 
4. IMPORTANT OPTIMALITY CHECK: if(popped_node_weight > dist[node])then continue 
- if(dist_till_now + weight_neighbour < dist[neighbour]), Then update the dist[neighbour] = dist[u] + weight, and push it into priority_queue
- [This process of updating the shortest path is called RELAXING AN EDGE]

#### DIJKSTRA V/S DP

##### 1. Grids [Movement Test]
- All 4 Directions[up,down,left,right] -> Dijkstra
- Only Down & Right -> DP [Standard DP Fails With Cycles]

##### 2. Cycle test
- Cycle Exist -> Dijkstra [It used Dist vector]
- No Cylce (DAG) -> DP

### 4. Bellman Ford [Shortest Path Weighted Graph -ve weight also, -ve CYCLE ALSO]
- USED FOR: Shortest path with Negative Weights or limiting "K" stops (Cheapest Flights).
- Detect -ve Cycle: Relax/Update Edges N-1 Times if still can relax 1 more time the -ve CYCLE Present
- HANDLE -ve Edges
- Dijkstra Greedy Once Node Processed, Distance is Final
- Bellman Ford Update (Relax) Every Edge N-1
- USED FOR: Connecting all nodes with minimum cost.


#### Algorithm TC: O(V.E) 
- WORKS ON EDGES 
1. Update/Relax Edges N-1 Times with Dijkstra Logic Without Min Heap 
2. if(dist[u] != INT_MAX && dist[u] + w < dist[v]) then dist[v] = dist[u] + w 
- dist[u] != INT_MAX check is important because we actually need to visit that node
3. In The end If again Able to Relax the Edge -> NEGATIVE CYCLE Present

### 5. Floyd Warshall [All Pairs Shortest Path] [-ve Cycle DETECT]
- Shortest Path From Everywhere To Everywhere
- -ve Edge Handle, But Not Handle -ve CYCLE
- Path Via ```i->k->j``` BETTER OR ```i->j```
- For Every Pair Check is Path via K dist[i][k] + dist[k][j]  Better than Direct Path dist[i][j]

#### TC/SC: O(V^3)/O(V^2)
- NOTE K-> Unlock Shortcut 1 by 1

#### ALGORITHM: 
1. Dist Array of N x N Size
2. Initial Edge Weight dist[u][v] = w, (dist[v][u]=w, if UNDIRECTED)
3. 3 Loops K then I then J
- Check i->k and k->j exists then dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
4. -ve Cycle detect if dist[i][i] is -ve then -ve CYCLE PRESENT


### 6. Prims [MST] [Prefer For DENSE Graphs -> More Edges]
- USED FOR: Connecting all nodes with minimum cost.
- Priority Queue + BFS
- Similar To Dijkstra Just focus on Weights ( Not added Distance)
- Unlike Dijkstra, Prim's uses a boolean visited array to ensure we don't re-add a node to the MST.

#### ALGORITHM:
1. Keep Min heap + Visited Array
2. Use BFS and push to pq {node,weight}

### 7. Kruskal [MST] [Prefer For SPARSE Graphs -> Less Edges]
- USED FOR: Connecting all nodes with minimum cost.
- TC: O(ElogE)
#### ALGORITHM 
- USE DSU
1. Sort The Edges By weight
2. If Parents of u and v NOT same then UNION(u,v) them and add the weight to MST_SUM

### 8. Bipartite Graph Check (Graph Coloring only 2 Colors [Use 0 & 1 to color & -1 Initially])
- If able to color Graph with only 2 colors then it is Bipartite Graph
- Use Colors vector and initialize it with -1 
- whenever color the neighbour do color[neighbour] = !color[front]
- NO ODD LENGTH CYCLES

#### ALGORITHM
1. Initialize color vector with -1 -> Not Initialized, 0 -> 1st Color, 1 -> 2nd Color
- Do Bipartite check, For All DISCONNECTED COMPONENTS & skip if color[i] != -1
2. color[start_node] = 0, **Do BFS,** 
- visit neighbour if(color[neighbour] == -1), then color it with !color[front]
- if color[neighbour] == color[front], then Same Color Adjacent, NOT BIPARTITE


### ***9. Bridges & Tarjan's Algorithm (Critical Connections) [V.V.IMP] [V.V.HARD]***
- We Find The Bridge, Bridge is the Edge which can connect a node to it's parent
- Bridge only when the NEIGHBOUR can't Reach back to curr_node

#### ALGORITHM
1. We initialize tin, low, timer [tin: Time of Insertion/Arrival, low: The lowest parent Which i can connect to]
2. Initially For every node the tin and low are same as timer, and mark curr_node as visited
3. We start with DFS on neighbours,
- We Don't consider the parent edge for now while visiting Neighbours
- If Neighbour is NOT VISITED, Do the DFS, and update your lowest with min(low[curr_node],low[neighbour])
- Now in same IF(!visited) condition, Check BRIDGE if(low[neighbour] > tin[curr_node]) Means the Neighbour can reach Strictly Below me and Consider the edge as a BRIDGE, bridges.push_back({node,neighbour})
- IMPORTANT: [Bridge Only when the neighbour can't go up to curr_node and there is no other way for neighbour to reach curr_node or to ancestors]
- IF Neighbour was Already VISITED, Then it is a Back Edge [ONE JUMP ONLY take "tin" memorize this] you can take low[curr_node] = min(low[curr_node],tin[neighbour])

```
BRIDGES
1 -  2 --- 3
     |     |
     |_____|

1 --- 2 is a bridge strictly below Node 1

ARTICULATION POINT
2 is Articulation Point removing it will disconnect the Graph
```

### 10. Articulation Points - Variation of Bridges.
- Same As Tarjan's Algorithm
- But neighbour can reach either curr_node or below then it is a Articulation Point
- For Bridge The neighbour has to strictly reach below curr_node
#### IMPORTASNT: **EXPLICITLY HANDLE ROOT**

- Only this condition Changed ">=" Check BRIDGE if(low[neighbour] >= tin[curr_node]) 
- **SPECIAL CASE: If Root is taken & it has 1 Child then Root think it is articulation point but it is not because Removing it will leave the entire remaining graph connected**
- If Root has more than 1 UNVISITED children then it will be an Articulation Point
#### Formula Don't work For Root, Explicitly Check if Root have More than 1 Children Then Only root will be an Articulation point
- Mark the Nodes Don't Push. Eg: 3 Branches for a node Each Seperately marks Curr_node as Articulation Point, But, we push_back in bridges {node,neighbour} because each branch is Unique

### 11. 0-1 BFS (Deque Optimization, instead of Min Heap)
- Concept: A modification of BFS/Dijkstra where edge weights are ONLY 0 or 1.
- Eg: Walk to Neighbour for free (cost 0) or break the wall (cost 1)
- Why: Dijkstra is O(Elog V). 0-1 BFS is O(E). It is strictly faster.
- Logic: Use a deque (Double Ended Queue).
- If weight is 0: Push to FRONT (Process immediately).
- If weight is 1: Push to BACK (Process later).
- Problem: Minimum Cost to Make at Least One Valid Path in a Grid (LeetCode 1368).

#### Where Used?
1. Grid Problems: Same Direction is 0 and breaking obstacle is 1

#### ALGORITHM
IT Use **DEQUE** Instead of **Min-HEAP** to maintain SORTED Property
1. If Edge is 0 Add to Front of deque ["High Priority"]
2. If Edge is 1 Add to Back of deque ["Low Priority"]
- This Causes deque to Remain Sorted
##### Do Same BFS as Dijkstra just carefully add into DEQUE 0 -> front, 1->back of Deque. Thus, maintaining it's Sorted Property

### 12. Hierholzer’s Algorithm (Eulerian Path)
#### **EULERIAN PATH :** Don't trace same edge twice
- Concept: Find a path that visits every edge exactly once.
- Why: It is the standard solution for the "Reconstruct Itinerary" problem (LeetCode 332).
- Logic: DFS that adds nodes to the path after visiting all neighbors (Post-order addition).
- Interview Status: Essential for specific "Route Reconstruction" problems.

- Eg: Draw a STAR without lifting pen

#### ALGORITHM EXAMPLE [Get Stuck, Then Backtrack]
- Keep Going To next Node till DEAD END [When DEAD END push_front]
- Then Backtrack and take another path

### 13. Max Flow (Ford-Fulkerson / Edmonds-Karp)
- You must understand the concept of "Max Flow Min Cut Theorem".
- Problem: "How many disjoint paths exist from S to T?
- "Google Pattern: They might frame a problem as a flow network, but usually, a DFS/BFS solution exists. I recommend skipping the implementation of this unless you have mastered everything else.


### NOTE: KRUSKAL & BELLMAN FORD & DSU -> Directly On Edges

| Algorithm | Main Concept | TC | SC | When to Use (Pattern) |
|---|---|---|---|---|
| **BFS** | Queue + visited | $O(V+E)$ | $O(V)$ | Shortest Path in unweighted graphs (Unit distance). Level-order traversal. |
| **DFS** | Recursion/Stack + visited | $O(V+E)$ | $O(V)$ | Connectivity, Finding ANY path, Cycle Detection, Backtracking logic. |
| **Kahn's Algo** | Indegree Array + Queue | $O(V+E)$ | $O(V)$ | Dependencies, Prerequisites, Build Order. Fails if Cycle exists. (DAG only). |
| **DSU (Union-Find)** | parent array + Path Comp. | $O(E \cdot \alpha(V)) \approx O(1)$ | $O(V)$ | Component, Cycle Detection in Undirected Graph, Grouping, Kruskal's. |
| **Dijkstra** | Min-Heap + dist array | $O(E \log V)$ | $O(V+E)$ | Shortest Path in Weighted (+ve) graphs. "Min Cost/Time/Delay". |
| **Bellman-Ford** | Relax all edges $(N-1)$ times | $O(V \cdot E)$ | $O(V)$ | Shortest Path with Negative Edges. Detects Negative Cycles. Max $K$ stops. |
| **Floyd-Warshall** | 3 Nested Loops (k outer) | $O(V^3)$ | $O(V^2)$ | All-Pairs Shortest Path. Small graphs ($N \le 500$). Multi-source routing. |
| **Prim's** | Min-Heap + visited | $O(E \log V)$ | $O(V+E)$ | MST (Dense Graphs). Connect all points cheaply. Logic like Dijkstra. |
| **Kruskal's** | Sorting + DSU | $O(E \log E)$ | $O(V)$ | MST (Sparse Graphs). Connect all points cheaply. Logic like Union-Find. |
| **Bipartite** | BFS/DFS + 2 Colors | $O(V+E)$ | $O(V)$ | Check for Odd Cycle. Split nodes into 2 independent sets. |
| **Tarjan's (Bridge)** | tin, low, DFS | $O(V+E)$ | $O(V)$ | Find Critical Connections. Edges that disconnect graph if removed. |
| **Tarjan's (AP)** | tin, low, Child Count | $O(V+E)$ | $O(V)$ | Find Critical Nodes. Vertices that disconnect graph if removed. |
| **Kosaraju** | DFS Order + Transpose + DFS | $O(V+E)$ | $O(V)$ | Strongly Connected Components (SCC) in Directed Graph. |

## PATTERNS GRAPHS
### 1. Multi Source BFS
1. Push all source nodes into queue
2. Now traverse them along with FOR loop of size = q.size()

### 2. Grid
1. Graph 2D GRID, use (row,col) to traverse not the adjacency list


# Heaps
It is a Complete Binary Tree (filled level-by-level, left-to-right).
- Max-Heap: Every parent is >= its children. Root Maximum.
- Min-Heap: Every parent is <= its children. Root Minimum.
## Array Representation (0-indexed)
index i:
- Left Child: ```2*i + 1```
- Right Child: ```2*i + 2```
- Parent: ```(i - 1) / 2```

## Core Operations (The "Heapify" Logic)
### 1. Insertion (push): O(log N)
- Add the new element to the End of the array (bottom-right leaf).
- Keep Comparing with Parent. If order  wrong (e.g., Child > Parent in Max-Heap), Swap.Repeat until the order is correct or Root is reached.

### 2. Deletion (pop - Removing Root): O(log N)
- Swap the Root (index 0) with the Last Element (index size-1).
- Remove the last element (the old root).
- (Heapify): Look at the new Root. Compare with Children, Swap with the larger child (in Max-Heap).Repeat down the tree until the order is correct.

### 3. Build Heap (from random array): O(N)
1. **STREAMING:** If Element come 1 by 1 then call ```.push()``` repeatidly ```TC: O(NlogN)```
2. **OFFLINE:** If Array Already present then apply HEAPIFY from Non Leaf Nodes to 0 and we automatically get the heap ```TC:O(N)```

## HEAPIFY O(N) [Already Present array]
- From n/2 -1 to 0 [Non Leaf Nodes] reapeatidly do Heapify b/w Curr,Left Child, Right Child get the smallest/greatest

## Max Heap
```
priority_queue<int>pq;
```
## Min Heap
```
priority_queue<int,vector<int>,greater<int>>pq;
```
## Custom Compare
```
struct CustomCompare{
  bool operator()(int a,int b){
    return a > b;    // MIN HEAP
  }
};
```

## HEAP SORT O(NlogN)
- Build Max Heap by Heapify then repeatidly get top and swap in the end
- Then call heapify from n-1 to 0 [as max element fixed to last position]

### Algorithm [Heap Sort O(NlogN) -> Max Heap]
```heap_sort(array)```
1. Build The Heap from given array Non Leaf to 0  [n/2-1 to 0]
2. from n-1 to 1 index ```SWAP(heap[0],heap[i])``` [Get Max Element At End] \& apply ```heapify```
3. Reassign arr = heap

## PATTERNS HEAP

### Pattern A: Top K Elements (The Reverse Logic)
- **Problem**: Find the K Largest elements.
- Use a MIN-Heap of size K.
- **Algo** 
- Get Minimum out of Largest K Elements
- ```(Why Min Heap? because keep on Discarding the Minimum Value when Overflow K Sized Heap and Eventually get Top K Elements)```
Rule:
- Find Largest K -> Min-Heap.
### For K Smallest
- MAX HEAP
- Get Maximum out of smallest K element
- Find Smallest K -> Max-Heap.

### Pattern B: Merge K Sorted Lists
- **Problem**: Merge K sorted arrays/lists.
- **Algo**: 
- Min-Heap, Push the head of all K lists into the Min-Heap.
- Pop the smallest (Root). Add to result.
- Push the next element from the list that the popped node came from.

### Pattern B[ii]: [Ugly Numbers 2]
#### **DYNAMICALLY KEEP TRACK OF MINIMUM**
- if i generate order manually and even after keeping track i can't track Nth Smallest Without Heap. 
- Eg: 1 then 2,3,5 are added now for 2-> 4,6,10 are added thus making [3,5,4,6,10] here we lose the Minimum so keep track using Min Heap and Take care of duplicates
- ```IMPORTANT: Don't Lose Sorted Order When New Elements Come```


### Pattern C: Two Heaps (Median)
- **Problem**: Find Median of a stream.
- **Algo**: 
- Maintain Max-Heap (Left half of data) and Min-Heap (Right half).
- Balance sizes so they differ by at most 1, 
- Median is the top of the larger heap (or average of both).
- ALWAYS PUSH TO LEFT First, then transfer top left to right and maintain N or N+1 elements in LEFT

### Pattern D: Scheduling [V.IMPORTANT]
- **Problem**: Task Scheduler, Meeting Rooms/ Locking Resource
- Sort by Start Time, use Min-Heap to track End Times (Availability).
#### **ALGORITHM**
- TC/SC: O(NlogN)/O(26)
- PATTERN [Hard]: SCHEDULING/ Locking Resource 
- ***[Map + Max_Heap + Queue]***
  - Where Map used for char->freq
  - Max_heap for Max Frequency First to Save IDLE Time
  - Queue For LOCKING till release_time

- First Free up resource from Queue if release_time and current_time matches
- Then Take top of Max_heap process it and store + Lock rest of Frequency-1 in Queue
- If max_heap is empty at any moment then IDLE time present


# Dynamic Programming [DP]

**RULE OF THUMB DP**
- Always return something 
- Don't use void with reference
```
int solve(int i){
  // BASE CASES
  ...
  int total = solve(i+1) + solve(i+2);
  ...
}
```
## "Why MEMOIZATION give TLE?" ```[V.V.V.IMPORTANT]```
```
Sometimes range like -10^4 <= cell[i][j] <= 10^4
Here if DP initialize to -1 then give TLE because Memoization Breaks...
Always Initialize with IMPOSSIBLE to REACH Value"
```

- Recursion : All Possibilities
- Memoization[Top-Down]: Before return result -> Write in Array. Before Computing -> Check Array.
- Tabulation [Bottom-Up]: Fill array Iteratively from Base Case up to answer

## Tabulation: Recursion in Reverse
CONVERT Recursive Solution -> Memoization -> TABULATION -> Space Optimization
1. Explicitly write base cases
2. Write a for loop after skipping INITIAL Case 
eg: 2 to N
3. IMPORTANT: declare a dp Table and fill With BASE CASE


## DP STATE FRAMEWORK
1. **State**: What variables change in my recursive function? (index, weight, prev_val...). These become your DP array dimensions.

2. **Transitions**: How do I move from state to next_state? (Pick vs Skip, Move Right vs Down).

3. **Base Case**: When do I stop? (Index out of bounds, Target reached).

## Decide DP V/S GRAPHS V/S GREEDY
### 1. The "Count/Min/Max" Trigger
- Does the problem ask for:
  - "Total number of ways..." (Count)
  - "Minimum cost/steps..." (Min)
  - "Maximum profit/length..." (Max)
  - "Is it possible to..." (True/False)
- If YES, it is likely DP or Graph.

### 2. The "Structure" Test (DP vs Graph)
- Graph: The input is explicit connections (Edges, Adjacency List) OR a Grid where you can move in all 4 directions (***Cycles possible***).
- DP: The problem has a Direction.
  - "Move only Right and Down" (Grid DP).
  - "Sequence i depends only on i-1" (1D DP).
  - "DAG (Directed Acyclic Graph)" logic.
- Key: No LOOPS, it is DP.

### 3. The "Choice" Test (DP vs Greedy)
- Greedy: "I can greedily pick the biggest/smallest item now, and I never regret it." (e.g., Activity Selection).
- DP: "I have choices (Pick/Skip, Buy/Sell). If I pick this now, it might prevent me from picking something better later. I need to **try ALL choices**."


## DP PATTERNS

### Pattern 1: 1D / Linear DP (Fibonacci Style)
Used for: Climbing Stairs, House Robber.

```
// Memoization
int solve(int i, vector<int>& dp) {
    if (i < 0) return 0;
    if (i == 0) return 1; // Base Case
    if (dp[i] != -1) return dp[i];
    
    // Transition: Try all steps (e.g., take 1 step or 2 steps)
    return dp[i] = solve(i-1, dp) + solve(i-2, dp);
}
```

### Pattern 2: Knapsack (Pick / Skip)
- Used for: Subset Sum, Partition, 0/1 Knapsack.
- State: dp[index][current_weight]

```
// Memoization
int solve(int i, int w, vector<vector<int>>& dp) {
    if (i == 0) return (items[0] <= w); // Base Case
    if (dp[i][w] != -1) return dp[i][w];
    
    int notPick = solve(i-1, w, dp);
    int pick = 0;
    if (items[i] <= w) pick = value[i] + solve(i-1, w - items[i], dp);
    
    return dp[i][w] = max(pick, notPick);
}
```

### Pattern 3: String DP (LCS)
- Used for: Longest Common Subsequence, Edit Distance.
- State: dp[i][j] (index in string 1, index in string 2).
```
int solve(int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0; // Base Case
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j]) 
        return dp[i][j] = 1 + solve(i-1, j-1, dp); // Match
    
    // Mismatch: Try skipping char from s1 OR skipping char from s2
    return dp[i][j] = max(solve(i-1, j, dp), solve(i, j-1, dp));
}
```

### Pattern 4: ```Digit DP``` (The 4D/5D Monster) ```[V.Important]```
- Used for: "Count numbers in range [L, R] that satisfy property X".
- State: dp[index][tight_constraint][leading_zeros][...property...]

```
long long solve(string& s, int idx, bool tight, int sum, vector<vector<vector<int>>>& dp) {
    if (idx == s.size()) return sum; // Base Case
    if (dp[idx][tight][sum] != -1) return dp[idx][tight][sum];
    
    int limit = tight ? (s[idx] - '0') : 9;
    long long ans = 0;
    
    for (int digit = 0; digit <= limit; digit++) {
        // Update tight constraint for next position
        bool nextTight = tight && (digit == limit);
        ans += solve(s, idx + 1, nextTight, sum + digit, dp);
    }
    return dp[idx][tight][sum] = ans;
}
```

###



