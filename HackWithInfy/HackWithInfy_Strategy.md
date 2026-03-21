
# Strategy
- Keyword: "Subarray" (Continuous) + "Sum / XOR" -> Prefix Sum Array.
- Keyword: "Range [L, R]" + "Add/Update/Increment" -> Difference Array.
- Keyword: "Minimum/Maximum" + "Is it possible to..." -> Binary Search on Answer.
- Keyword: "Subtree" + "Sum/Max" -> Tree DFS.

# The "N" Constraint Rule:
1. N <= 20: O(2^N) or O(N!). -> Think: Backtracking, Recursion, Bitmasking.
2. N <= 500: O(N^3). -> Think: 3D DP, Matrix Chain Multiplication (Burst Balloons), Floyd Warshall Graph.
3. N <= 2500: O(N^2). -> Think: 2D DP (LCS, Edit Distance), Nested for loops.
4. N <= 10^5 (THE HACKWITHINFY SWEET SPOT): O(N log N) or O(N). -> Think: Sorting, Greedy, Two Pointers, Sliding Window, Prefix Sums, Binary Search, Difference Arrays, Trees/Graphs. (If you write a nested for loop here, you fail).
5. N <= 10^9: O(log N) or O(1). -> Think: Math formulas, Binary Search on Answer.

## Block 1: The Array & Range Query Superpowers (Days 1 - 3)
HackWithInfy loves giving you an array of 10^5 elements and asking you to do 100,000 updates to it. A simple loop will TLE.
- **KEYWORDS**: N with Q Queries on [L,R] Range

### Day 1: The Difference Array & Prefix Sum. 
(Directly solves Q3 and Q5 from your PDF). This will also cure your Sliding Window anxiety.
#### A. Prefix Sum O(N+Q)
The Trap: You have an array of size $10^5$. The question gives you $10^5$ queries. Each query says "Find the sum (or XOR) from index $L$ to index $R$". If you use a for loop from $L$ to $R$ for every query, the time complexity is $O(Q \times N) = 10^{10}$. TLE.

- **For Sum:** Sum of range ```[L, R] = Prefix[R] - Prefix[L-1]```
- **For XOR** (Question 5 in your PDF): Exactly the same! XOR of range ```[L, R] = Prefix[R] ^ Prefix[L-1]``` (Because XORing 0 to L and 0 to R cancels out 0 to L and gives XOR L to R)
- if ```L is 0 then return R ``` OR ```Use 1-Based Indexing to avoid this check```
- {Why L-1 because to include Left Sum}

#### B. Difference Array O(Q + N) [HackWithInfy Favourite]
The Trap (Question 3 in your PDF): You have an array of size $10^5$ initialized to 0. You are given $10^5$ queries. Each query says: "Add value $V$ to every element from index $L$ to index $R$."
If you loop from $L$ to $R$ adding $V$, it takes $O(Q \times N) = 10^{10}$. TLE.

#### TIP: Difference Array
- not necessarily array elements in Question all 0 initially
- but create difference_Arr with all 0, 
- ```SOURCE: diff[L] += Value```
- ```DRAIN: diff[R+1] -= Value```
- Prefix_Sum Calculate
- final_Ans[i] = arr[i] + diff[i]

##### ANALOGY [Valve] Source[L], DRAIN[R+1]:
- N=6
- **Query:** Add 10 from index 1 to 3. ($L=1$, $R=3$, $X=10$).
- We create our diff array of size 7 (always make it $N+1$ to avoid out-of-bounds when doing $R+1$). ```diff = [0, 0, 0, 0, 0, 0, 0]```
  - Step 1: Turn the valve ON at $L$
    - diff[1] += 10;
    - diff is now: [0, 10, 0, 0, 0, 0, 0]
    - Prefix Sum of this right now? [0, 10, 10, 10, 10, 10, 10].
    - Awesome! Indices 1, 2, and 3 got the 10. 
    - But oh no! Indices 4, 5, and 6 ALSO got the 10, because the prefix sum carries the number forward forever!
  - Step 2: Turn the valve OFF at $R+1$
    - We want the 10 to stop after index 3. 
    - This means at index 4, we need to cancel it out.
    - How do you cancel a +10 flowing towards you? You add a -10.
    - ```diff[R + 1] -= 10```  $\implies$  ```diff[4] -= 10```;
    - diff is now: [0, 10, 0, 0, -10, 0, 0]
  - Step 3: Let the water flow (The Final Prefix Sum)
    - Final Array: [0, 10, 10, 10, 0, 0]
    - Exactly indices 1, 2, and 3 got the 10. Everything else is 0




### Day 2: Binary Search on Answer (BSoA). 
The absolute most common CP pattern. "Find the minimum time/maximum weight..."
- Final Question Sentence: 
  - Minimum, 
  - Maximum, 
  - minimum of maximum, 
  - maximum of minimum, 
  - Least Amount of time
- Constraints:
  - N <= 10^5, with values massive 10^9 or 10^14 ---> **O(N log(Range))**
- Pattern: Monotonic Boundary(Range Of Possible Answers) ```[fail,fail,fail,fail,success,success,success]```

#### Binary Search on Answer EXAMPLE:
- ```Eg:1``` Book 100 pages in 5 Days exam, laziest possible way to read book or ```MINIMUM NUMBER OF PAGES PER DAY```
  1. Take 10 pages a day -> 100/10 = 10 Days (NOT POSSIBLE)
  2. Take 50 pages a day -> 100/50 = 2 Days (Success, But NOT LAZIEST)
  3. Take 20 pages a day -> 100/20 = 5 Days (Success, Laziest)

- ```Eg:2``` Total 50 Dollars, 1 Burger Cost 8 Dollars, How much Greediest i can be for Burgers, Without going Broke or ```MAXIMUM NUMBER OF BURGERS YOU CAN EAT```
  1. Take 10 Burgers -> Total 80 Dollars (BROKE, NOT POSSIBLE)
  2. Take 2 Burgers -> 16 Dollars (Success, But NOT GREEDIEST(Money Left))
  3. Take 6 Burgers -> 48 Dollars (Success, GREEDIEST)

#### Minimum or Maximum **[Question Framing ANALOGY]**
- "Find the Minimum..." -> "```What is the laziest I can be without failing?```"
- "Find the Maximum..." -> "```What is the greediest I can be without breaking the rules?```"

#### Binary Search on Answer in 2 parts:

1. **The `isValid(mid)` Function (The Tester):**
   You pretend the answer is `mid`. You write a simple $O(N)$ loop to check: *"If my truck capacity is exactly `mid`, can I successfully move all the boxes under the given rules?"* It returns `true` or `false`.
2. **The Binary Search (The Optimizer):**
   You set `low` = worst case minimum answer, and `high` = worst case maximum answer.
   You calculate `mid`. 
   * If `isValid(mid)` is `true` $\implies$ Awesome! Save `mid` as the best answer so far, but try to find a *smaller* one by searching the left half (`high = mid - 1`).
   * If `isValid(mid)` is `false` $\implies$ The truck is too small. Search the right half (`low = mid + 1`).



### Day 3: Blind Story-Stripping (Array/BS Edition). 
I will throw 3 confusing stories at you. You extract the logic and code them.

## Block 2: The SP3 Tree & Graph Meta (Days 4 - 6)
Look at Part 2 of your PDF. They love asking queries about "Subtrees".

### Day 4: DP on Trees & Subtree Queries. 
How to use DFS to calculate values for an entire subtree in O(N) time.
- USE: **```POSTORDER DFS O(N)```** -> every Subtree Question
- KEYWORDS:
  - "There are $N$ cities/nodes connected by $N-1$ roads/edges." 
  - "The network is rooted at node 1 (or node 0)."
  - "You are given $Q$ queries. For each query, find the ```sum/maximum/count``` in the subtree of node $U$."
  - Query always ask about a Single Node U

- The Time Limit Trap: 
  - If you get $10^5$ queries, and for every query you run a fresh search to find the subtree answer, it takes $O(N \times Q) = 10^{10}$ operations. You will TLE (Time Limit Exceeded).
  - The Solution: You must pre-calculate the answer for every single subtree in exactly one pass ($O(N)$), store it in an array, and then answer the $Q$ queries instantly ($O(1)$).

- CODE:-
  - **adj_list + node_value + subtree_value**
  - in DFS -> Subtree[curr_node] = curr_node_val + curr_node_child_subtree
  - **UNDIRECTED EDGES**
  - DFS Logic Change:
    - The Start: ```subtree[curr_node] = values[curr_node];```
      - Sum/Count Problems: You start with your own value.
      - Max/Min Problems: You start with your own value.
      - Distance Problems: You start at 0 (because distance to yourself is 0).
    - MERGE:  ```subtree[curr_node] += subtree[child];```
      - Sum/Count Problems: ```+=```
      - Maximum in Subtree: subtree[curr_node] = max(subtree[curr_node], subtree[child]);
      - XOR of Subtree: subtree[curr_node] ^= subtree[child]


```
// Global or Class variables
vector<vector<int>> adj; // The Adjacency List (Who is connected to who)
vector<long long> subtree_ans; // Stores the final answer for every node
vector<int> values; // The individual values of each node

// The "Corporate Chain of Command" Function
void dfs(int current_node, int parent_node) {
    
    // Step 1: Start with my own personal value
    subtree_ans[current_node] = values[current_node];
    
    // Step 2: Ask all my direct reports (children)
    for(int child : adj[current_node]) {
        
        // Don't accidentally ask your boss! (Infinite loop)
        if(child != parent_node) {
            
            // Tell the child to calculate their department first
            dfs(child, current_node); 
            
            // Step 3: The child is done. Merge their answer into mine!
            subtree_ans[current_node] += subtree_ans[child]; 
        }
    }
}
```


### Day 5: Shortest Path Variations. 
#### NOTE:
```
Dijkstra -> O(ElogV)
Use BELLMAN FORD O(V.E) when unsure and contraints allow in OA Round
```
Dijkstra modified for "Delivery Drones" (Q8 in your PDF).
- KEYWORDS:
  - "Find the ```minimum time/cost/distance``` to travel from ```POINT A``` to ```POINT B```"
  - "There are ```N``` cities and ```M``` roads. Each road has a ```weight/cost```."
  - "You can travel in ```any direction```."
#### ALGORITHM:-
1. distances array, initialized to INFINITY
2. starting node with distance 0 in PRIORITY_QUEUE(Min-Heap)
3. Neighbours
  - Take Closest neighbour
  - if ```curr_dist + Road Cost < Known distance neighbour``` -> SHORTCUT

#### CODE:
```
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int N, int start_node, vector<vector<pair<int, int>>>& adj) {
    // 1. The Notebook (Initialize all distances to Infinity)
    vector<int> dist(N + 1, 1e9); 
    dist[start_node] = 0;
    
    // 2. The Min-Heap (Stores pairs of {accumulated_cost, current_node})
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node}); // Cost is 0 to reach the start node
    
    // 3. The Expansion
    while(!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        // If we found a slower path in the queue, ignore it
        if(current_cost > dist[current_node]) continue;
        
        // Look at all neighbors
        for(auto& edge : adj[current_node]) {
            int neighbor = edge.first;
            int road_weight = edge.second;
            
            // Is this a shortcut?
            if(current_cost + road_weight < dist[neighbor]) {
                dist[neighbor] = current_cost + road_weight; // Write it in the notebook
                pq.push({dist[neighbor], neighbor}); // Add to queue to explore later
            }
        }
    }
    return dist;
}
```

---
### Negative Weights Graphs [```Bellman Ford Algorithm```]
- Use: BELLMAN FORD Algorithm
#### ALGORITHM
1. Relax/update Edges N-1 times
  - if(dist[u] + w < dist[v]) then update 
2. If still able to relax/update then ```-ve Cycle Present```

### Day 6: Blind Story-Stripping (Tree/Graph Edition).

## Block 3: The CP Dynamic Programming & Greedy (Days 7 - 9)
We aren't doing random DP; we are doing HackWithInfy DP.

### Day 7: State Machine DP & Subsets. [1D Array + Strict Restriction]
(House Robber III, Stock Cooldown, and Q2/Q9 from your PDF).

#### KEYWORDS:
1. 1D DP: Array size N, represents timeline (move left or right)
2. State DP : Recognize max or min with ```"BUT"``` -> ```STRICT RESTRICTION```
  - Eg: "Find the max sum... **BUT** you cannot pick adjacent elements."
  - "Find the max profit... **BUT** you must wait 1 day after selling."
  - "Find the min cost... **BUT** you can only hold 1 item at a time."

#### Greedy V/s DP
- Eg: [10,20,15] -> No Adjacent Elements Pick
- GREEDY: Pick best choice 20 but is blocked
- DP: Picks 10 and then 15 to get higher sum
- Greedy Fails, Pick DP

#### ANALOGY [Stock with Cooldown]

**The "What button can I click?" Method.**

#### How to Create ```States``` from Scratch [IMPORTANT]

Forget arrays. Forget math. Imagine you are playing a video game. A "State" is just the answer to one simple question: **Based on my current situation, what buttons light up on my controller?**

**Stock with Cooldown** problem just by pretending we are playing the game. We will start with a blank piece of paper and write down the states as they happen.

**1. The Start of the Game:**
* You wake up on Day 1. You have no stock. You have no penalties.
* What button is lit up on your controller? **[BUY]** (or you can just do nothing).
* *Let's write this situation down on our paper:* 👉 **STATE 1: "Ready to Buy"**

**2. You press the [BUY] button:**
* The game changes. You now have a stock in your hand. The rules say "you can only hold one stock at a time."
* Because you have a stock, the [BUY] button goes dark. You cannot press it.
* What button lights up instead? **[SELL]**. 
* *This is a brand new situation. Let's write it down:*
  👉 **STATE 2: "Holding"**

**3. You press the [SELL] button:**
* The game changes again. You hand the stock over and get your profit. 
* Can you press [BUY]? No, the rules say "after selling, you must wait 1 day."
* Can you press [SELL]? No, you don't have a stock anymore.
* What buttons are lit up? **None.** You are forced to just hit **[NEXT TURN]** to rest. 
* *This is a brand new situation. Let's write it down:*
  👉 **STATE 3: "Cooldown"**

**4. You press [NEXT TURN] (Your 1 day of rest finishes):**
* The penalty is gone. You don't have a stock. 
* What button lights up? **[BUY]**. 
* Have we seen this situation before? Yes! This is exactly State 1. The loop is closed.

**Look at your paper.** You just naturally discovered the 3 states without memorizing anything. 
The states are just the different "modes" your controller can be in!
1. Mode 1: [BUY] is active. ("Ready")
2. Mode 2: [SELL] is active. ("Holding")
3. Mode 3: Everything is locked. ("Cooldown")

***

### Let's Test This Method Together

I am going to give you a brand new story. I don't want you to write any code. I don't want you to do any math. 

I just want you to use the **"What button can I click?"** method to trace the game and tell me how many States there are.

 **The Story: The Gladiator Training**
 You are a gladiator preparing for a tournament. Every day, you can choose to click the **[TRAIN]** button to gain stats, or the **[REST]** button to do nothing.
 
 **The Rule:** Training is exhausting. If you click **[TRAIN]** for exactly 2 days in a row, your body breaks down. On the next day, the [TRAIN] button will be locked, and you are forced to click **[REST]**.

**Your Turn:**
Imagine you are playing this game. Wake up on Day 1. Trace your button clicks. Tell me the different "Situations" (States) your character can find themselves in. How many are there?



### Day 8: Advanced Greedy. 
(Part 3 PDF: "Exercises to get tired"). Sorting combined with priority queues.
### Day 9: Blind Story-Stripping (DP/Greedy Edition).










# Other Hack With INFY Topics [SP3]
- DP: 0/1 knapsack, LCS, digit DP, matrix exponentiation
- TRIE: Autocomplete, Word Dictionary
- Segment Trees & Fenwick Trees(Binary Indexed Tree)
- Heavy Light Decomposition (for trees)
- XOR + Bitmasking
- Game Theory
- String Matching Algo(KMP, Z Algos)

# HWI Video Preperation
## EASY (1/4th of total marks)
- Segment Tree
- Fenwick Tree
- Red Black Tree
- Radix Tree
- KD Tree
- B,B+ Tree
- Any other on similar lines

## MEDIUM (1/3rd of total marks)
Advanced problems involving multiple steps & optimizations
- On top of EASY
- Greedy
- DP

## HARD [Primarily DP]
- On top of Medium
- DP problem with additional shortlisted Technique:-
  - Bit-mask
  - Hashing
  - Backtracking
  - Lazy Propogation
  - Prefix Sum
  - Experimental
    - Sum over substes
    - MO's algorithm
  - Graph Theory
    - Any other families, eg: Bipartite, flow networks
    - Any other on similar lines

## Navigator Session 1
- Segment Tree
  - Find in approx 1 or 2 or 3 Efficient Operation
  - When Use [Fast Range Queries & Updates sum/min/max] on arrays
- Fenwick Tree
  - Find Sum of element in Range [a,b], Inversion Count
- TRIE O(L) -> Insert/Search/Delete
  - String Presence in array
  - Autocomplete, Spell Checker, Prefix Search
  - Eg: Phone Dictionary, Word Search

## Navigator Session 2 [Dynamic Programming]

- DP + Graphs [Type 1 and Type 2 Query type questions]



# 3. Greedy + Sorting: 
(Part 3 PDF: "Minimum exercises to get tired"). This isn't DP; it's just sorting the array descending and subtracting!

 