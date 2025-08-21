C++ Contest Cheat Sheet — paste this in README.md

# If n ≤ 3000 → O(n^2) OK in C++; if n near 1e5 → O(n) or O(n log n) is required.
# (Then check the inner-loop cost and sum of n for multiple testcases.)

# 🔍 Golden rule

Always base algorithm choice on input sizes (e.g. n = nums.length, q, V, E, or “sum of n over tests”). The value range of elements (nums[i]) only matters when it enables special techniques (counting sort, bucketing, bitmask tricks), not for asymptotic time complexity.

# ⏱ Quick complexity thresholds (practical)

- n ≤ 20 → exponential / O(2^n) or O(n!) OK
- n ≤ 200 → O(n^3) sometimes OK
- n ≤ 1,000 → O(n^2) OK
- n ≈ 3,000 → O(n^2) usually OK in C++ (≈9e6 ops)
- n ≈ 10^4 → prefer O(n log n) or optimized O(n √n)
- n ≈ 10^5 → aim for O(n) or O(n log n)
- n, q ≈ 10^5 → per-query must be O(log n) or O(1)

# 🕒 30s decision checklist (during a contest)

- Read constraints: n, q, sum of n over tests.
- If n ≤ 3000, O(n^2) is often fine—check inner work.
- If n ≥ 1e5, prefer O(n) or O(n log n).
- If values have small range R, consider counting/radix (O(n + R)).
- If multiple test cases, use sum of n constraint to estimate total work.

# ⚙️ Micro-optimizations (easy wins in C++)

- Use int where safe; long long for sums that may overflow.
- Put ios::sync_with_stdio(false); cin.tie(nullptr); at start.
- Use '\n' instead of endl.
- Cache .size() in loops (int n = v.size();).
- reserve() vectors / unordered_map::reserve() to avoid rehashing.
- Avoid allocations / heavy work inside inner loops.
- Use references in ranged-for: for (auto &x : v).

# 🔧 Useful STL snippets (copy-paste)

# Fast I/O & typedefs

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ...
}


# Two-pointer after sort

sort(a.begin(), a.end());
int l = 0, r = n-1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) break;
    if (sum < target) ++l;
    else --r;
}


# Prefix-sum frequency (subarray count = k)

unordered_map<ll,int> freq;
freq.reserve(n*2);
freq.max_load_factor(0.7);
freq[0] = 1;
ll pref = 0;
int ans = 0;
for (int x : nums) {
    pref += x;
    if (freq.count(pref - k)) ans += freq[pref - k];
    freq[pref]++;
}


# Difference array (range add, final array in O(n))

vector<ll> diff(n+1,0);
for (auto &q : queries) { // q = {l,r,val}
  diff[l] += val;
  diff[r+1] -= val; // if r+1 < n
}
vector<ll> arr(n);
arr[0] = diff[0];
for (int i = 1; i < n; ++i) arr[i] = arr[i-1] + diff[i];


# nth_element for k-th smallest (expected O(n))

nth_element(a.begin(), a.begin() + k, a.end());
int kth = a[k];


# Reserve unordered_map/set

unordered_map<int,int> mp;
mp.reserve(n*2);
mp.max_load_factor(0.7f);

# 🔁 Common patterns & target complexities

- Two-sum: O(n) (hash) or O(n log n) (sort+2p).
- 3-sum: O(n^2) (sort + two-pointer), OK when n ≤ 3000.
- LIS: O(n log n) for n up to 1e5.
- Subarray sum == k: O(n) prefix+map.
- Range add & final array: O(n + q) difference array.
- Many queries (updates + queries): segment tree / BIT O(log n) per op.
- Graph BFS/DFS: O(V + E).
- Bitmask DP: O(n * 2^n) if n ≤ 20; meet-in-the-middle if n ≤ 40.

# 🧠 Memory rules

- Avoid O(n^2) memory unless n ≤ ~2000.
- vector<vector<int>> dp(n, vector<int>(n)) with n = 3000 → ~9M ints (~36MB); check judge limits.
- Prefer O(n) or O(n log n) memory where possible.

# ⚠️ Common contest pitfalls

- Using .size() in nested loops repeatedly (cache it).
- Using endl (causes flush).
- Allocating inside inner loops.
- Forgetting sum-of-n across test cases.
- Overusing unordered_map without reserve() → rehash cost/TLE.

# ✅ Sanity-check practice (quick)

For each, pick complexity and justify briefly:

- n = 3000, 3-sum → O(n^2) sort + two-pointer.
- n = 1e5, LIS → O(n log n) patience algorithm.
- n = 40, subset sum → meet-in-the-middle O(2^(n/2)).
- n = 2e5, q = 2e5, range add → O(n + q) using difference array.


If n ≤ 3000 → O(n^2) OK in C++; if n near 1e5 → O(n) or O(n log n) is required.
(Then check the inner-loop cost and sum of n for multiple testcases.)