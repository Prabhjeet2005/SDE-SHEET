#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* --------------------------------------------------
                    MCM
 -------------------------------------------------- */

int matrixChainMultiplication(vector<int> &p)
{
  int n = p.size();
  // dp[i][j] stores minimum operations to multiply matrices A[i]...A[j]
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // L is chain length (from 2 to n-1)
  for (int L = 2; L < n; L++)
  {
    for (int i = 1; i < n - L + 1; i++)
    {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;

      // Try every split point k
      for (int k = i; k <= j - 1; k++)
      {
        int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (cost < dp[i][j])
          dp[i][j] = cost;
      }
    }
  }
  return dp[1][n - 1];
}

int main()
{
  // Dimensions of matrices: A=1x2, B=2x3, C=3x4
  vector<int> arr = {1, 2, 3, 4};
  cout << "Min Operations: " << matrixChainMultiplication(arr) << endl;
  return 0;
}