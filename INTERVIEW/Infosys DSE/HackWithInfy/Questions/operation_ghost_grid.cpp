/*
### 💻 HackWithInfy Blind Challenge: Operation Ghost-Grid

**Problem Statement:**
You are the lead engineer for a classified cyber-long longelligence tool tasked with monitoring a dark web routing network. The network consists of `N` sequential proxy servers, indexed from `0` to `N-1`. Each server is currently routing a specific amount of encrypted malicious traffic, given by an array `T`, where `T[i]` represents the initial terabytes of data flowing through the `i-th` server.

A notorious cyber syndicate is actively trying to mask their operations by flooding segments of your network with decoy traffic. Your system must handle a real-time log of `Q` events. These events are either syndicate attacks or system long longelligence sweeps:

* **The Decoy Flood (Event Type 1):** The syndicate launches a massive botnet surge. They target a continuous subnet of servers from index `L` to `R` (inclusive) and inject exactly `V` terabytes of decoy traffic long longo **every single server** in that range.
* **The long longelligence Sweep (Event Type 2):** Your decryption engine needs to allocate bandwidth. It initiates a sweep from server `L` to `R` (inclusive) and requires the **absolute total sum** of all traffic (malicious + decoy) currently routing through that specific subnet.

If your long longelligence sweep takes too long, the syndicate's operations will vanish long longo the dark web. You must process these events with maximum efficiency.

**Constralong longs:**
* 1 <= N <= 10^5
* 1 <= Q <= 10^5
* 0 <= T[i] <= 10^5
* 0 <= L <= R < N
* 1 <= V <= 10^4
* **Time Limit:** 1.0 seconds
* Use 64-bit long longegers (`long long` in C++) to prevent overflow during sum calculations.

**INPUT FORMAT:**
Line 1: An long longeger `N`, the number of servers.
Line 2: `N` space-separated long longegers, representing the initial traffic array `T`.
Line 3: An long longeger `Q`, the number of events.
Next `Q` lines:
* For a Decoy Flood, the line will be `1 L R V`.
* For an long longelligence Sweep, the line will be `2 L R`.

**Sample Input:**

5
2 5 1 4 9
4
2 1 3
1 0 2 10
2 1 3
2 0 4


**Sample Output:**

10
30
51


*/

#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeLazy
{
  vector<long long> tree;
  vector<long long> arr;
  vector<long long> lazy;
  long long n;

  void push_down(long long node, long long start, long long end)
  {
    if (lazy[node] != 0)
    {
      tree[node] += lazy[node] * (end - start + 1);

      if (start != end)
      {
        long long left_child = 2 * node + 1;
        long long right_child = 2 * node + 2;
        lazy[left_child] += lazy[node];
        lazy[right_child] += lazy[node];
      }

      lazy[node] = 0;
    }
  }

  void build_segment_tree_lazy(long long node, long long start, long long end)
  {
    if (start == end)
    {
      tree[node] = arr[start];
      return;
    }
    long long mid = start + (end - start) / 2;
    long long left_child = 2 * node + 1;
    long long right_child = 2 * node + 2;

    build_segment_tree_lazy(left_child, start, mid);
    build_segment_tree_lazy(right_child, mid + 1, end);

    tree[node] = tree[left_child] + tree[right_child];
  }

  // Range Update Instead of Polong long Update
  void update_segment_tree_lazy(long long node, long long start, long long end, long long L, long long R, long long value)
  {
    push_down(node, start, end);
    // Completely Outside
    if (start > R || end < L)
    {
      return;
    }
    // Completely inside
    if (start >= L && end <= R)
    {
      tree[node] += value * (end - start + 1); // FIX: value here not lazy[node]
      if (start != end)
      {
        long long left_child = 2 * node + 1;
        long long right_child = 2 * node + 2;
        lazy[left_child] += value;
        lazy[right_child] += value;
      }
      return;
    }

    // Partially Inside
    long long mid = start + (end - start) / 2;
    long long left_child = 2 * node + 1;
    long long right_child = 2 * node + 2;

    update_segment_tree_lazy(left_child, start, mid, L, R, value);
    update_segment_tree_lazy(right_child, mid + 1, end, L, R, value);

    tree[node] = tree[left_child] + tree[right_child];
  }

  long long query_segment_tree_lazy(long long node, long long start, long long end, long long L, long long R)
  {
    push_down(node, start, end);
    // Completely Outside
    if (start > R || end < L)
    {
      return 0;
    }

    // Completely Inside
    if (start >= L && end <= R)
    {
      return tree[node];
    }

    long long mid = start + (end - start) / 2;
    long long left_child = 2 * node + 1;
    long long right_child = 2 * node + 2;

    long long left_ans = query_segment_tree_lazy(left_child, start, mid, L, R);
    long long right_ans = query_segment_tree_lazy(right_child, mid + 1, end, L, R);

    return left_ans + right_ans;
  }

public:
  SegmentTreeLazy(vector<long long> input_arr)
  {
    n = input_arr.size();
    arr = input_arr;
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    build_segment_tree_lazy(0, 0, n - 1);
  }

  void update(long long L, long long R, long long value)
  {
    update_segment_tree_lazy(0, 0, n - 1, L, R, value);
  }

  long long query(long long L, long long R)
  {
    return query_segment_tree_lazy(0, 0, n - 1, L, R);
  }
};

class Solution
{
public:
  void solution()
  {
    vector<long long> arr = {2, 5, 1, 4, 9};
    vector<vector<long long>> queries = {{2, 1, 3}, {1, 0, 2, 10}, {2, 1, 3}, {2, 0, 4}};

    SegmentTreeLazy seg_tree_lazy = SegmentTreeLazy(arr);

    for (auto &query : queries)
    {
      long long type = query[0];
      if (type == 1)
      {
        long long L = query[1], R = query[2], V = query[3];
        seg_tree_lazy.update(L, R, V);
      }
      else
      {
        long long L = query[1], R = query[2];
        cout << seg_tree_lazy.query(L, R) << "\n";
      }
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}