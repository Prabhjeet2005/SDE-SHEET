## Q1 Rune Transformation Power
### 📝 Quick-Recall Cheat Sheet: String Segmenting & Reduction

**The Core Concept:**
When characters move and leave "dead" zones behind, stop looking at individual characters. **Group identical adjacent characters into contiguous blocks (segments).**

**The Mental Model:**

* **X Blocks = Targets** (`cSX`)
* **Y Blocks = Missiles** (`cSY`)
* **Rule of Engagement:** 1 Missile Block can only destroy 1 Target Block.

**The Implementation Trick (The `while` Loop):**
To group continuous characters, use an inner `while` loop inside your main `for` loop.

* **Crucial Step:** Always use `i--` immediately after the `while` loop so the outer `for` loop doesn't skip the next character.

**The 3-Step Decision Tree (The Final Output):**
Count your total 'X's (`cX`). Your goal is to return `cX` unless mathematically impossible.

1. **Enough Missiles? (`cSX <= cSY`):** You have enough Y blocks for every X block.
* *Result:* Destroy everything. Output = `cX`.


2. **Split Missiles? (`flg == true`):** You found at least one `YY` block. It can split left and right, acting as two missiles to save you.
* *Result:* Destroy everything. Output = `cX`.


3. **Forced Sacrifice (`else`):** You have more Targets than Missiles (e.g., `X Y X Y X`) and no `YY` to split. Exactly one X block *must* survive.
* *Result:* Sacrifice the smallest block to maximize points. Output = `cX - smallSeg`.



## Q3 Gridpolis Critical Blocks
### Split Into 3 Neighbourhoods
* **Pattern Identify**
* . . .
* x . x
* **OR**
* x . x     -> Pinched Row
* . . .     -> Open Row

* Here putting X in top middle will create 3 neighbourhoods: Top Left, Top Right, Bottom Middle
* Main aim is to find a Open row and a pinched row

Here is the breakdown for the fourth question from the PDF.

## Question 4: The Kingdom's Rebellion (Create Adj_List if no Pointer given)

### 📝 Quick-Recall Cheat Sheet: Kingdom's Rebellion

**The OA Trap:**
Lengthy descriptions of "reassigning children" and "dynamic tree updates" are often **Red Herrings**.

**The Mental Model:**

* A parent's removal requires all its children to be rebels.
* Moving rebel children to a new parent does not change the mathematical truth of the tree.
* **Conclusion:** The problem is static. No simulation required.

**The Implementation Trick:**

1. Use `vector<vector<int>> adj` to store `adj[parent].push_back(child)`.
2. Loop `1` to `N` (handles the smallest index rule for free).
3. If node is a rebel `&&` no children are loyal -> Print it.

Does the "Red Herring" trap make sense here? Let me know if you want to trace a specific example before we move to Question 5!



## Question 5: Parcel Count Maximization
### 📝 Quick-Recall Cheat Sheet: Parcel Count Maximization

**The OA Trap:**
The problem hides a simple gap-closing math puzzle behind a confusing story about "permutations" and "parcel updates."

**The Mental Model (The 2 Rules):**

1. **Duplicates are Dead Weight:** You are adding a permutation (unique numbers). If two boxes start with the exact same number, it is mathematically impossible for them to reach the same final target. **Action: Destroy all duplicates.**
2. **The "Closing Power" limit:** The biggest boost you have is `N`, the smallest is `1`. Therefore, the absolute maximum gap you can close between the smallest box and the largest box is exactly `N - 1`. **Action: The gap between boxes in your group must be `< N`.**

**The Implementation Trick:**

1. Filter the array through an `unordered_map` to remove all duplicates.
2. **Sort** the unique array in ascending order.
3. Use a **Sliding Window** (Two Pointers: `i` for left, `j` for right) to find the longest valid group where the difference is `< N`.

---

* Gap is < N because 1 to N so Max_boost is N and Min_Boost is 1 so max-min boost is N-1

---

**Code Core Logic (Mental Snapshot):**

```cpp
// 1. Array is already filtered of duplicates and sorted

int ans = 0;
int j = 0; // Right pointer

for (int i = 0; i < arr.size(); i++) { // 'i' is Left pointer
    
    // As long as the gap is valid (strictly less than N), expand right!
    while (j + 1 < arr.size() && arr[j + 1] - arr[i] < n) {
        j++;
    }
    
    // Save the maximum window size (Right - Left + 1)
    ans = max(ans, j - i + 1); 
}

```

---
## Question 6: Nearest Meeting Cell
### 📝 Quick-Recall Cheat Sheet: Nearest Meeting Cell

**The OA Trap:**
Do not use a Multi-Source BFS. Mixing the starting points in one queue makes it impossible to track which node reached the cell first.
Do not build a 2D Adjacency List. A single array jump is faster.

**The Mental Model:**

1. Run a standard BFS strictly from `C1` to map all its reach times.
2. Run a standard BFS strictly from `C2` to map all its reach times.
3. The "Meeting Time" for any cell is the `max(dist1, dist2)`. We want the cell that provides the absolute minimum of these maximums.

**The Implementation Trick:**

* **The Array Jump:** `int next_cell = arr[current_cell];`
* **The Validation:** `if (next_cell != -1 && dist[next_cell] == 1e9)`
* **The Final Loop:** Loop `0` to `N-1`. If both distances `< 1e9`, check if `max(dist1, dist2)` is your new minimum. If yes, save the index `i`.

---
## Question 7: Largest Sum Cycle
**Use Kahn's Algorithm**
* Check all indegree 0 or Non Cycle Nodes and put them in queue and remove them, if neighbor also drop indgree to 0 put it in queue
* After snipping all non-cycle, count sum of all cycles and mark them visited as you go
* Return Max Sum Cycle
1. Count all Indegree
2. Remove non cylces by indegree 0
3. Sum all leftover, keep track of each cycle sum

### 📝 Quick-Recall Cheat Sheet: Largest Sum Cycle

**The Trigger:**

* Input is a 1D array (`Edge[i]`).
* Nodes have at most 1 exit.
* Asking to find/measure Cycles.
* $N >= 10^5$ (Stack Overflow risk for DFS).

**The Mental Model (Kahn's Graph Peeling):**

1. **Count Arrows:** Build an `indegree` array.
2. **Queue Dead Ends:** Push all nodes with `indegree == 0`.
3. **Snip Branches:** Pop the queue, mark `visited`, and subtract $1$ from the neighbor's `indegree`. If the neighbor hits $0$, push it.
4. **Harvest the Cycles:** Whatever is `!visited` at the end is part of a cycle. Run a `while(!visited)` loop to traverse the loop, adding to a `long long` sum.

**Critical Edge Cases to Remember:**

* **Data Types:** Summing up to $10^5$ indices WILL overflow an `int`. Default to `long long` for graph summation metrics.
* **The "No Cycle" Rule:** Read the return requirements carefully. Usually, it requires a `-1` if the graph is entirely stripped away by the Kahn's queue.








