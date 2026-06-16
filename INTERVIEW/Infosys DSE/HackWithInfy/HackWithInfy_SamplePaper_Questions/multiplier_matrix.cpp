/*

### 💻 HackWithInfy Challenge A: The Multiplier Matrix

**Problem Statement:**
You're given an array `A` of `n` integers and `q` queries. Each query can be one of the following two types:

* **Type 1 Query:** `(1, l, r)` - Replace `A[i]` with (i - l + 1) x A[l] for each index `i`, where l <= i <= r.
* **Type 2 Query:** `(2, l, r)` - Calculate the sum of the elements in `A` from index `l` to index `r`.

Find the sum of answers to all Type 2 queries. Since the answer can be large, return it modulo 10^9+7.

**Sample Input:**

7
1 4 5 1 6 7 8
5
1 1 6
1 1 5
2 5 5
2 3 4
2 3 3


**Sample Output:**

60

*(Explanation from the document: For query 4 `(2, 3, 4)`, sum = `A[3] + A[4] = 28`. For query 5 `(2, 3, 3)`, sum = `A[3] = 12`. The previous queries also added 20. Total = 60).*

---

*/

#include <iostream>
#include <vector>
using namespace std;
/*
How To Solve?
- Calculate First 3 terms
FORMULA: (i - L + 1) * A[L]

1st term : (L - L + 1) * A[L]         -> A[L]
2nd term : ((L + 1) - L + 1) * A[L]   -> 2*A[L]
3rd term : ((L + 2) - L + 1) * A[L]   -> 3*A[L]
*/

class SegmentTreeLazy
{
  vector<int> arr;
  vector<int> tree;
  vector<int> lazy_a;
  vector<int> lazy_d;
  int n;

  void push_down(int node, int start, int end)
  {
    if (lazy_a[node] != 0 || lazy_d[node] != 0)
    {

      int a = lazy_a[node];
      int d = lazy_d[node];
      int n = end - start + 1;

      int sum_ap = (n * (2 * a + (n - 1) * d)) / 2;
      tree[node] = sum_ap; // Acc to Ques: REPLACE Not ADD

      if (start != end)
      {
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        lazy_a[left_child] = a; 
        lazy_d[left_child] = d;

        int number_left_elements = mid - start + 1;
        // SHIFT RIGHT START: a + (No. Left elements) * d
        int right_start_a = a + (number_left_elements * d);
        lazy_a[right_child] = right_start_a;
        lazy_d[right_child] = d;
      }
      lazy_a[node] = 0;
      lazy_d[node] = 0;
    }
  }

  void build_segment_tree(int node, int start, int end)
  {
    if (start == end)
    {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    build_segment_tree(left_child, start, mid);
    build_segment_tree(right_child, mid + 1, end);

    tree[node] = tree[left_child] + tree[right_child];
  }

  // RANGE UPDATE
  void update_segment_tree(int node, int start, int end, int L, int R, int A, int D)
  {
    push_down(node, start, end);
    // COMPLETELY OUTSIDE
    if (start > R || end < L)
    {
      return;
    }
    // COMPLETELY INSIDE
    if (start >= L && end <= R)
    {
      int n = end - start + 1;
      int elements_skipped = (start - L);
      int updated_a = A + (elements_skipped * D); // Got to Actual Start

      tree[node] = (n * (2 * updated_a + (n - 1) * D)) / 2;
      if (start != end)
      {
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        lazy_a[left_child] = updated_a;
        lazy_d[left_child] = D;

        // Right SubTree Start [Skipping past left elements]
        int number_left_elements = mid - start + 1;
        int right_start_a = updated_a + (number_left_elements * D); // got to Actual Right start
        lazy_a[right_child] = right_start_a;
        lazy_d[right_child] = D;
      }
      return;
    }
    // PARTIALLY INSIDE
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    update_segment_tree(left_child, start, mid, L, R, A, D);
    update_segment_tree(right_child, mid + 1, end, L, R, A, D);

    tree[node] = tree[left_child] + tree[right_child];
  }

  int query_segment_tree(int node, int start, int end, int L, int R)
  {
    push_down(node, start, end);
    // COMPLETELY OUTSIDE
    if (start > R || end < L)
    {
      return 0;
    }
    // COMPLETELY INSIDE
    if (start >= L && end <= R)
    {
      return tree[node];
    }
    // PARTIALLY INSIDE
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    int left_ans = query_segment_tree(left_child, start, mid, L, R);
    int right_ans = query_segment_tree(right_child, mid + 1, end, L, R);

    return left_ans + right_ans;
  }

public:
  SegmentTreeLazy(vector<int> input_arr)
  {
    arr = input_arr;
    n = arr.size();
    tree.resize(4 * n, 0);
    lazy_a.resize(4 * n, 0);
    lazy_d.resize(4 * n, 0);
    build_segment_tree(0, 0, n - 1);
  }

  void update(int L, int R, int A, int D)
  {
    update_segment_tree(0, 0, n - 1, L, R, A, D);
  }

  int query(int L, int R)
  {
    return query_segment_tree(0, 0, n - 1, L, R);
  }
};

int main()
{
  cout << "\n";
  vector<int> arr = {1, 4, 5, 1, 6, 7, 8};
  vector<vector<int>> queries = {{1, 1, 6}, {1, 1, 5}, {2, 5, 5}, {2, 3, 4}, {2, 3, 3}};
  SegmentTreeLazy st = SegmentTreeLazy(arr);
  long long total_sum = 0;
  int MOD = 1e9 + 7;

  for (auto &query : queries)
  {
    int type = query[0], L = query[1], R = query[2];
    if (type == 1)
    {
      /*
        How To Solve?
        - Calculate First 3 terms
        FORMULA: (i - L + 1) * A[L]

        1st term : (L - L + 1) * A[L]         -> A[L]
        2nd term : ((L + 1) - L + 1) * A[L]   -> 2*A[L]
        3rd term : ((L + 2) - L + 1) * A[L]   -> 3*A[L]
      */

      // FIX: ask Segment Tree for A and D as they might get changed arr[L] never changes
      int ad = st.query(L, L);
      int A = ad;
      int D = ad;
      st.update(L, R, A, D);
    }
    else
    {
      total_sum += (st.query(L, R) % MOD);
    }
  }
  cout << "Total Sum: " << total_sum;
  cout << "\n";
}