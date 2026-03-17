
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
### Day 5: Shortest Path Variations. 
Dijkstra modified for "Delivery Drones" (Q8 in your PDF).
### Day 6: Blind Story-Stripping (Tree/Graph Edition).

## Block 3: The CP Dynamic Programming & Greedy (Days 7 - 9)
We aren't doing random DP; we are doing HackWithInfy DP.

### Day 7: State Machine DP & Subsets. 
(House Robber III, Stock Cooldown, and Q2/Q9 from your PDF).
### Day 8: Advanced Greedy. 
(Part 3 PDF: "Exercises to get tired"). Sorting combined with priority queues.
### Day 9: Blind Story-Stripping (DP/Greedy Edition).


# 1. Prefix Arrays & Math: 
(Q1, Q4, Q5 in your Question Bank). They love asking for XORs in a range or sums with odd/even conditions.

# 2. Difference Arrays / Lazy Propagation: 
(Q3: "increment every element in A[l] to A[r] by val"). If you do this with a for loop, you get TLE. You must know the Difference Array trick.

# 3. Greedy + Sorting: 
(Part 3 PDF: "Minimum exercises to get tired"). This isn't DP; it's just sorting the array descending and subtracting!

# 4. Trees & Subtrees: 
(Part 2 PDF: "Query in the subtree of node S"). 