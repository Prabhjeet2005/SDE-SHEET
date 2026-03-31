/*

### 💻 Practice Challenge: The Overlapping Waves (AP Addition)

**Problem Statement:**
You are given an array `A` of `N` integers, initially all zeros. You must process `Q` queries of two types:

* **Type 1 (Wave Addition):** `1 L R X Y`
  A wave hits the array from index `L` to `R` (inclusive).
  It *adds* `X` to `A[L]`, *adds* `X + Y` to `A[L+1]`, *adds* `X + 2Y` to `A[L+2]`, and so on, until index `R`.
* **Type 2 (Sum Query):** `2 L R`
  Calculate the total sum of elements from index `L` to `R`. Return the answer modulo 10^9 + 7.

**Constraints:**
* 1 <= N, Q <= 10^5
* 0 <= L <= R < N (0-based indexing)
* 1 <= X, Y <= 10^4

**Sample Input:**

5
4
1 1 3 5 2
2 1 2
1 2 4 1 3
2 1 4


**Sample Output:**

12
33


*/

#include <iostream>
#include <vector>
using namespace std;
int MOD = 1e9+7;
// DYNAMIC RANGE UPDATION -> Lazy Propogation (Type: AP)
class SegmentTreeLazy
{
  vector<int> arr;
  vector<int> tree;
  vector<int> lazy_a; // Start
  vector<int> lazy_d; // Common Difference
  int n;

  void push_down(int node, int start, int end)
  {
    if (lazy_a[node] != 0 || lazy_d[node] != 0)
    {
      int n = end - start + 1;
      int a = lazy_a[node];
      int d = lazy_d[node];
      tree[node] += ((n * (2 * a + (n - 1) * d)) / 2)%MOD; // SUM AP

      if (start != end)
      { // NOT LEAF
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        lazy_a[left_child] += a; // Left remain same // FIX: All Lazy Add UP
        lazy_d[left_child] += d; // FIX: All Lazy Add UP

        int count_left_half = (mid - start + 1);
        int updated_a = a + (count_left_half * d); // Right First is a+(n*d)
        // Right Shifts by Left Elements
        lazy_a[right_child] += updated_a; // FIX: All Lazy Add UP
        lazy_d[right_child] += d;         // FIX: All Lazy Add UP
      }
    }
    lazy_a[node] = lazy_d[node] = 0;
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

  void update_segement_tree(int node, int start, int end, int L, int R, int A, int D)
  {
    push_down(node, start, end);
    // CASE : Completely OUTSIDE
    if (start > R || end < L)
    {
      return;
    }
    // CASE : Completely INSIDE
    if (start >= L && end <= R)
    {
      int elements_L_to_start = start - L;
      int n = end - start + 1;
      int d = D;
      int a = A + (elements_L_to_start * d); // Nth TERM: a + (n * d)

      tree[node] += ((n * (2 * a + (n - 1) * d)) / 2)%MOD;

      if (start != end)
      {
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        lazy_a[left_child] += a; // FIX: All Lazy Add UP
        lazy_d[left_child] += d; // FIX: All Lazy Add UP

        // Shift Right Elements by count of Left Elements
        int left_elements_count = mid - start + 1;
        lazy_a[right_child] += a + (left_elements_count * d); // a + (n * d)
        lazy_d[right_child] += d;                             // FIX: All Lazy Add UP
      }
      return; // FIX: Forgot
    }
    // CASE : Partially INSIDE
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    update_segement_tree(left_child, start, mid, L, R, A, D);
    update_segement_tree(right_child, mid + 1, end, L, R, A, D);

    tree[node] = tree[left_child] + tree[right_child];
  }

  int query_segment_tree(int node, int start, int end, int L, int R)
  {
    push_down(node, start, end);
    // CASE : Completely OUTSIDE
    if (start > R || end < L)
    {
      return 0;
    }
    // CASE : Completely INSIDE
    if (start >= L && end <= R)
    {
      return tree[node];
    }
    // CASE : Partially INSIDE
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    int left_ans = query_segment_tree(left_child, start, mid, L, R);
    int right_ans = query_segment_tree(right_child, mid + 1, end, L, R);

    return left_ans + right_ans;
  }

public:
  SegmentTreeLazy(vector<int> &input_arr)
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
    update_segement_tree(0, 0, n - 1, L, R, A, D);
  }
  int query(int L, int R)
  {
    return query_segment_tree(0, 0, n - 1, L, R);
  }
};

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {0,0,0,0,0};

    vector<vector<int>> queries = {{1,1,3,5,2},{2, 1, 2}, {1, 2, 4, 1, 3}, {2, 1, 4}};
    SegmentTreeLazy st = SegmentTreeLazy(arr);
    /*
    A[L] = X
    A[L+1] = X+Y
    A[L+2] = X + 2Y
    A -> X, D -> Y
    */
    for (auto &query : queries)
    {
      // 1 L R X Y
      // 2 L R -> SUM
      int type = query[0], L = query[1], R = query[2];
      if (type == 1)
      {
        int X = query[3], Y = query[4];
        st.update(L, R, X, Y);
      }
      else
      {
        cout<<st.query(L, R)<<"\n";
      }
    }
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  cout<<"OUTPUT:\n";
  sol.solution();
  cout << "\n";
}