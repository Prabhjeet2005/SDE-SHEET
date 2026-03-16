# The "N" Constraint Rule:
1. $N \le 20$: $O(2^N)$ or $O(N!)$. $\to$ Think: Backtracking, Recursion, Bitmasking.
2. $N \le 500$: $O(N^3)$. $\to$ Think: 3D DP, Matrix Chain Multiplication (Burst Balloons), Floyd Warshall Graph.
3. $N \le 2500$: $O(N^2)$. $\to$ Think: 2D DP (LCS, Edit Distance), Nested for loops.
4. $N \le 10^5$ (THE HACKWITHINFY SWEET SPOT): $O(N \log N)$ or $O(N)$. $\to$ Think: Sorting, Greedy, Two Pointers, Sliding Window, Prefix Sums, Binary Search, Difference Arrays, Trees/Graphs. (If you write a nested for loop here, you fail).
5. $N \le 10^9$: $O(\log N)$ or $O(1)$. $\to$ Think: Math formulas, Binary Search on Answer.