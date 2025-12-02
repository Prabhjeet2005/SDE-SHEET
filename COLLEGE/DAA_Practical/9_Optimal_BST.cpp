#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* --------------------------------------------------
                    OPTIMAL BST
 -------------------------------------------------- */

// Function to calculate sum of frequencies from i to j
int sum(const vector<int> &freq, int i, int j)
{
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}

int optimalBST(vector<int> &keys, vector<int> &freq, int n)
{
  // cost[i][j] = Optimal cost of binary search tree that can be formed from keys[i] to keys[j]
  vector<vector<int>> cost(n, vector<int>(n));

  // For a single key, cost is equal to its frequency
  for (int i = 0; i < n; i++)
    cost[i][i] = freq[i];

  // L is chain length (2 to n)
  for (int L = 2; L <= n; L++)
  {
    for (int i = 0; i <= n - L; i++)
    {
      int j = i + L - 1;
      cost[i][j] = INT_MAX;

      // Try making 'r' the root
      for (int r = i; r <= j; r++)
      {
        // c = cost when keys[r] becomes root of this subtree
        int c = ((r > i) ? cost[i][r - 1] : 0) +
                ((r < j) ? cost[r + 1][j] : 0) +
                sum(freq, i, j);
        if (c < cost[i][j])
          cost[i][j] = c;
      }
    }
  }
  return cost[0][n - 1];
}

int main()
{
  vector<int> keys = {10, 12, 20};
  vector<int> freq = {34, 8, 50};
  int n = keys.size();
  cout << "Cost of Optimal BST is " << optimalBST(keys, freq, n);
  return 0;
}