
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

### Day 7: State Machine DP & Subsets. [1D Array Timeline + Strict Restriction] 
* ```STATE```: What each day Represent. ```Eg: travelling_illussionist.cpp```

* For Eg: See 
  * ```alchemy_reactor.cpp```
  * ```lunar_solar_grid.cpp```
  * ```syndicate_courier.cpp```

* (House Robber III, Stock Cooldown, and Q2/Q9 from your PDF).

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

#### How to Create ```States``` from Scratch [IMPORTANT]
* Think of Different days i could be in
* Then for new just think how i can be on that stage

**EXAMPLE**
* Initially well rested
* Grand Rest Earlier, take full element
* Basic done Consecutively, take half floor(arr[i]/2)
```
void solution(int N, vector<int>&arr){
    // A Day Could be either of Following
    long long rest = 0;         // INITIALLY WELL RESTED so 0
    long long grand = -1e15;    
    long long basic = -1e15;

    for(int i=0; i<N; i++){
      // if grand today then previously i must rest
      long long new_grand = rest + arr[i] ; 
      // basic today then previous basic and rest allowed
      long long new_basic = max(basic,rest) + floor(arr[i]/2) ; 
      // rest today then previously i could rest, grand or basic
      long long new_rest = max({grand,rest,basic}) + 0 ; 

      grand = new_grand;
      basic = new_basic;
      rest = new_rest;

    }
    cout<< max({grand,rest,basic});
  }
```


### Day 8: Advanced Greedy. 
(Part 3 PDF: "Exercises to get tired"). Sorting combined with priority queues.
* ```Free Up availabilty as fast as POSSIBLE```

**KEYWORDS ```intergalactic_merchant.cpp```**
* ```Fractions``` Allowed, start/end time, infinte supply, Divisible
* Taking Item A doesn't restrict from picking Item B
* **```CONSTRAINTS```** check for constraints. Eg: if weight:10^5, value:10^6 -> DP Not Possible dp[weight][value] give TLE 10^11

**How?**
* Value To Weight Ratio (Value/Weight[i])
* Earliest Finish Time first

**Greedy ANALOGY ```[IMPORTANT]``` ```cyber_bounty_hunter.cpp```**
* ***Take Everything Right Now if die UNDO biggest mistake***

#### Patterns [GREEDY]
**1. ```SORTING ALLOWED``` (Pattern 1)**

* The Mask: Interval Scheduling (Sorting by end time), Fractional Knapsack (Sorting by Ratio), or Constructive Strings (Sorting largest blocks first, like your Mock Test).

* The Core: You have all the data up front. find mathematical "best" metric, sort it, and sweep left-to-right.

**2. ```SORTING NOT ALLOWED``` (Pattern 2)**

* The Mask: Any problem where you must process items in a ```strict sequence``` (like moving through a dungeon or time), and you have a ```limited resource``` (health, fuel, money).

* The Core: You use a Min/Max Heap to aggressively take everything, and "undo" your worst decisions only when you are about to fail.


**TEMPLATE [ADVANCED GREEDY]**
* 1. Group the data together in a struct
```

struct Job {
    int start;
    int end;
};
```


* 2. Build the "Custom Rule" function. 

```
static bool compareJobs(Job a, Job b) {
    // We want the earliest end time first!
    return a.end < b.end; 
}
```

* 3. Main Code

```

int main() {
    vector<Job> jobs = {{1, 10}, {2, 4}, {3, 6}, {5, 8}};
    
    // 3. Sort the array using your custom rule
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    // Now the array is perfectly arranged for a Greedy sweep!
    int jobs_done = 0;
    int current_time = -1; // Keep track of when you are free
    
    for(int i = 0; i < jobs.size(); i++) {
        // If the job starts AFTER I am free, take it!
        if(jobs[i].start >= current_time) {
            jobs_done++;
            current_time = jobs[i].end; // My new free time is when this job ends
        }
    }
    
    cout << "Max Jobs: " << jobs_done << "\n";
    return 0;
}
```


# MAANG `Important Topics`
* Segment Trees
* BitMasking
* String Manipulation
* Tries

# 1. Segment Trees (The Range Masters) 
**`patterns/Segment_Tree/segment_tree.cpp`**

**`patterns/Segment_Tree/neon_grid_crisis.cpp`**

**The Core Concept:** answer queries about a specific range `[L, R]` (like the sum, minimum, or maximum) AND `update` elements in the array, both in `O(log N)` time.

**Contest Identifying Triggers:**
* The problem asks you to perform **both** "`updates`" and "`queries`" on an array.
* The constraints are usually $10^5$, meaning an `O(N)` scan per query will result in a Time Limit Exceeded (TLE). 
* Keywords: "Range", "Subarray [L, R]", "Update index i", "Find the maximum between L and R".

**Patterns to Crush:**
* **Point Update & Range Query:** The vanilla segment tree (e.g., update one element, find the sum of a range).
* **Range Update & Range Query (Lazy Propagation):** The interviewer's favorite. You need to update an entire range `[L, R]` at once without tanking your time complexity.

**Segment Tree STRUCTURE**
* Root Stores Sum of Left + Right Half
* Leaves Actual array element
* ***`Each Parent Node in tree store SUMMARY of Left and Right Child`***

**NOTE**
* Tree -> 1D Array of Size **$4 \times N$**
* Root -> Sum [0,N-1], Left Half -> Sum [0,mid], Right Half -> Sum [mid+1,N-1]
* Left Child: `2*index+1`
* Right Child: `2*index+2`

**`[L,R]` is the Question and `[start,end]` is Range of each Node**

**`Query` Functions**
* **Completely Outside**
  * Stop & Return 0 (Sum Query) or Infinity (Min query)
  * Eg: [L,R] = [3,5], [start,end] = [0,2]
* **Completely Inside**
  * Stop & Return tree[node] Value
  * `[IMPORTANT]` All Remaining Range given by other Nodes
  * Eg: [L,R] = [1,5], [start,end] = [2,4]
* **Paritally Overlap**
  * Some values it has some it doesn't
  * Keep Breaking It down till it reaches `Completely Inside` or `Completely Outside`
  * Eg: [L,R] = [2,5], [start,end] = [1,3]


## Lazy Segment Tree `[Lazy Propogation]` For Range Query + `Range Updates`
* `HackWithInfy/patterns/Segment_Tree/segment_tree_lazy_propogation.cpp`
* `HackWithInfy/Questions/operation_ghost_grid.cpp`

**Standard Segment Tree:** 
* You use this when you have `Range Queries + Point Updates`
* (e.g., "Change the power at sector 3 to 10").

**Lazy Propagation:** 
* You use this when you have `Range Queries + Range Updates` 
* (e.g., "Add 10 to every sector from index 2 to 8").

**NOTE:`[IMPORTANT]`**
* For Sum do `tree[node] += lazy[node] * (end - start + 1)` -> Increase sum children by Number
* For Max or Min just add `tree[node] += lazy[node]`

### Lazy Segment Tree V/s Standard Segment Tree
*(What changes from a Standard Segment Tree)*

**1. The Two Workstations**
You only ever apply updates in exactly two places: 
* `push_down()`
* `update()` (specifically in the "Completely Inside" case).

**2. The Standard Action (The 1-2 Punch)**
Whenever you are at those two workstations, you always do the exact same two things:
* **Step 1:** Update `tree[node]` immediately. (For Range Sum: `+= value * (end - start + 1)`).
* **Step 2:** Add the value to `lazy[left_child]` and `lazy[right_child]`. **Never touch the children's `tree` directly.**

**3. The `push_down` Rule**
* **Where:** It must be the absolute **first line** inside your `update` and `query` recursive functions. 
* **What it does:** Checks if `lazy[node]` has a value. If yes, it does the "1-2 Punch" using `lazy[node]`, then resets `lazy[node] = 0`.

**4. The `update` Function Overhaul**
* Because Range Updates cover intervals, `update` no longer acts like Binary Search.
* It now uses the **exact same 3 overlap cases** (Completely Outside, Completely Inside, Partially Inside) as the `query` function. 
* You stop recursion and do the "1-2 Punch" at the **Completely Inside** case.

### Lazy Segment Tree `Dynamic Increase` [Actually asked 90%] `[Very Important]`

* **Arithmetic Progression (AP) in Lazy Segment Trees**
* **Increase in [L,R] everytime by X (e.g: 2,10+2,23+4, 52+6 ... Everytime increase by 2)**

**NOTE:**
* Always Calculate First 3 Terms
* Eg: Formula -> (i - L + 1) * A[L]
  * 1st term : (L - L + 1) * A[L]         -> `A[L]`
  * 2nd term : ((L + 1) - L + 1) * A[L]   -> `2*A[L]`
  * 3rd term : ((L + 2) - L + 1) * A[L]   -> `3*A[L]`

**TYPES LAZY PROPOGATION**
#### 1. The Static Family (Level 1)
* **Signatures:** "Add V to range", "Replace range with V".
* **The Math:** `tree[node] += V * elements` or `tree[node] = V * elements`.
* **The Sticky Note:** Just one variable (`lazy`).

#### 2. The AP Family (Level 2) 
**SAMPLE CODE:** 
* `HackWithInfy/HackWithInfy_SamplePaper_Questions/multiplier_matrix.cpp`
* `HackWithInfy/Questions/overlapping_waves.cpp`
***
**`TIP:`** Always Write AP Formula First then think of variables required for it and then write code IT is MUCH EASIER THIS WAY
***
* **Signatures:** "Add X + i * Y", "Replace with (i-L) * V".
* **The Math:** The AP Sum Formula `(n/2) * (2a + (n-1)d)`, **Nth Term:** `a + (n * d)`.
* **The Sticky Note:** Two variables (`lazy_start`, `lazy_diff`). Left child gets `start`, right child gets `start + (left_elements * diff)`.



**Formulas(`First write formula then Take Variables Required for it`):**
* `a` and `d` come directly from Question
* Sum AP:  `(n * (2 * a + (n-1) * d)) / 2`
* Right Start Value: `a + (n) * d` -> Here +1 otherwise it will give last element of Left Side
* Here n = `(end - start + 1)` and for right_start = `a + (left_number_element * d)` and left_number_elements = `mid - start + 1`



#### 3. The `Bitwise` Family (The Boss Level) `[IMPORTANT]` 
* **Signatures:** "XOR all elements in range with X", "Flip all bits (0 to 1, 1 to 0) in the range".
* **The Math:** You don't use AP formulas here. 
    * *Example (Flipping Bits):* If a node represents 10 elements, and its current sum is 3 (meaning there are three `1`s and seven `0`s). If you flip the range, the seven `0`s become `1`s. The new sum is simply `Total Elements - Old Sum` **(10 - 3 = 7)**.
    * *Example (XOR):* If you XOR a range with a value X, the result depends on whether the number of elements in that range is odd or even!
* **The Sticky Note:** A single variable (e.g., `lazy_flip` boolean, or `lazy_XOR` value). 



--------------------------
BITWISE SEGMENT TREE HERE
--------------------------



---

# 2. Bitmasking (The State Compressors)
**The Core Concept:** Using the binary representation of an integer to represent a subset or a combination of items. 

**Contest Identifying Triggers:**
* **Extremely small constraints.** If you see `N <= 20` or `N <= 15`, it is almost a 100% guarantee that it is a Bitmasking problem (often combined with DP).
* Keywords: "All possible subsets", "Permutations", "Combinations", "Assign N people to N tasks".
* Heavy use of the `XOR`, `AND`, or `OR` operators in the problem description.

**Patterns to Crush:**
* **Core Bit Manipulation:** Shifts, Masks, Bit is Set and XOR
* **Bitwise Magic:** Properties of XOR (e.g., $A \oplus A = 0$), checking if a bit is set, Brian Kernighan’s algorithm (counting set bits).
* **Subset Generation:** Iterating through all 2^N subsets using a simple `for` loop.
* **Bitwise Segment Tree:** `push_down` and  `update`
* **DP with Bitmasking:** The Travelling Salesman Problem (TSP), Job Assignment Problem. (This is a guaranteed "Hard" level question on OAs).

## Bit Manipultation
### Basic Operations
**1. And (&)**
* USED: `Checking`, `Clearing` Bits
* Example: 1010 & 0010 = 0010
* `IMPORTANT:` While checking `(num1 & num2) != 0` should be done (as it can either give 0 or some decimal number, it doesn't give 0 or 1 it give 0 or actual DECIMAL NUMBER like 10,45...etc)

**2. OR (|)**
* USED: `Setting` bits
* Example: 1010 | 0101 = 1111

**3. XOR (^)**
* USED: Toggle and Find Unique Elements (Different Remain Same, Same Become 0)
* Example: 1010 ^ 0110 = 1100

**4. Left Shift (<<)**
* USED: Fast Multiply by 2
* Example: 0011 << 1 = 0110 (3 become 6)

**5. Right Shift (>>)**
* USED: Fast Division by 2
* Example: 0110 >> 1 = 0011 (6 become 3)

### 🏆 The MAANG Bitwise Cheat Sheet [Important Bit Formulas]
**TERMINOLOGY**
* `Set Bit` : 1
* `Unset Bit` : 0
* `Lowest` : Rightmost
* `Lowest Set Bit` : Rightmost 1

**1. Drop Lowest Set Bit** `patterns/bit_manipulation/bit_manipulation_question.cpp`
* **FORMULA:** `N & (N-1)`
* MEANING: Only Turn Rightmost 0 
* [`Application`: **Count Set Bits** `while(num!=0){N = N & (N-1); count++}`]
* [`Application`: **Check Power of 2** `(N & (N-1)) == 0` because power of 2 only have one '1' (e.g: 8 in Binary 1000 -> if drop only rightmost 1 then become 0)]
* Eg: 12 -> `1100` -> N & (N-1) -> `1000`

**2. Isolate Lowest Set Bit**
* **FORMULA:** `N & -N`
* MEANING: Only have Rightmost 1
* Eg: 12 -> `1100` -> N & (-N) -> `0100`

---
### 🕵️‍♂️ The OA Strategy: How to read a problem

When the clock starts in a MAANG Online Assessment, follow this exact flowchart:

1. **Check the Constraints First:** Is N <= 20? If yes, immediately stop thinking about anything else. It is **Lens 3 (Bitmasking)**.
2. **Look for "Duplicates":** Does the problem mention numbers appearing multiple times? If yes, it is **Lens 1 (Annihilator)** or **Lens 2 (Vertical Sweep)**.
3. **Look for "Pairs/Sum/Max":** Does it ask for the sum of all XORs, or the max XOR? It is **Lens 2 (Vertical Sweep)** (often combined with a Trie).
4. **Look for "Counting/Powers":** Does it ask about the bits themselves? It is **Lens 4 (Bit Stripper)**.
---

### 🧠 The Four Bitwise Lenses (Your Mental Framework)

#### Lens 1: The Annihilator (XOR Magic) 
* `patterns/bit_manipulation/bit_manipulation_question.cpp`
* **The Identifying Triggers:** * "Every number appears K times, except one/two."
  * "Find the missing number."
  * "Find the unique element."
* **The Thought Process:** Can I make the duplicates destroy each other? If it's pairs, `A ^ A = 0` solves it instantly. If it's two unique numbers, I use `N & -N` to separate them into two buckets and XOR them again.

#### Lens 2: The Vertical Sweep (32-Bit Columns) `IMPORTANT`
*(This is how you solve the "Triple Threat" problem I gave you previously!)*
* **The Identifying Triggers:** * The Annihilator fails (e.g., numbers appear 3 times instead of 2).
  * "Sum of XORs of all pairs in the array."
  * "Maximum XOR pair in an array."
* **The Thought Process:** Stop looking at the array as a list of decimal numbers. Imagine it as a grid of 32 vertical columns. I will write a `for (int i = 0; i < 32; i++)` loop. For each column, I will count how many `1`s and `0`s there are. I will build my final answer bit-by-bit from these counts. 

#### Lens 3: The Subset Generator (Bitmasking)
* **The Identifying Triggers:** * **N <= 20.** (This is the biggest giveaway in all of competitive programming).
  * "Find all combinations."
  * "Assign N workers to N tasks."
  * "Travelling Salesman Problem."
* **The Thought Process:** I need to represent a combination of choices. An integer has 32 bits. I can use an integer from $0$ to $2^N - 1$. If the $i$-th bit is `1`, I "pick" the item. If it's `0`, I "skip" the item. 

#### Lens 4: The Bit Stripper (Brian Kernighan's Math)
* **The Identifying Triggers:** * "Count the number of 1s."
  * "Hamming Weight" or "Hamming Distance."
  * "Check if it's a Power of 2."
  * "Find the next power of 2."
* **The Thought Process:** The problem specifically asks about the *properties* of the bits themselves, not combinations. I will use `N & (N - 1)` to repeatedly drop the lowest set bit, or `N & -N` to isolate it.

---
### Application Lenses
**Lens 1: Array Duplicates and 2 unique numbers**
* If it's pairs, `A ^ A = 0` solves it instantly. If it's two unique numbers, I use `N & -N` to separate them into two buckets and XOR them again.

**Lens 2: Vertical Sweep**

```
arr = {2,2,2,7,7,7,3};
2  ->  0 0 1 0
2  ->  0 0 1 0
2  ->  0 0 1 0
7  ->  0 1 1 1
7  ->  0 1 1 1
7  ->  0 1 1 1
3  ->  0 0 1 1
----------------
SUM->  0 3 7 4 
HERE Divisible by 3 because 3 times number coming
```
* Loop 32 Times
* Iterate each and Create a `mask` for `1` at $i^{th}$ position `int mask = 1 << i`
* For each element check if $`i^{th}`$ bit turned on `num[i] & mask != 0`, if so then increase bit_sum
* if bit_sum % 3 != 0 then here exists bit for UNIQUE Number `(3 because there are 3 reptition of a number)` `!= 0 is used because (num[i] & mask) give 'decimal number' not 0 or 1`
  * If So, then set the bit of `unique_number = unique_number | mask`


---

# Trie
* O(L) Time 
* Create `vector<TrieNode*>children` with 26 Pointers and `end_of_word` flag
* **Insert** -> use index and add the word at end put `end_of_word=true`
* **Search** -> Search Entire Word and at end check if end_of_word
* **start_with** -> Prefix Search and return false if path break and at end return true
* **delete** -> Just traverse to last character and make `end_of_word = false`

## Bitwise Trie
`Max Xor between 2 numbers`

**When**
* Max Xor, Min Xor, Subarray Max XOR, Find A ^ B >= K



# DP + Bitmasking











# Bit Manipulation, Segment Trees [PRIORITY]

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


 