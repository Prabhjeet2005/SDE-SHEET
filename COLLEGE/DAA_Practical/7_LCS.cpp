#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max

using namespace std;

/* --------------------------------------------------
                    LCS
 -------------------------------------------------- */

int longestCommonSubsequence(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();

  // Create a 2D vector initialized with 0
  // Size is (n+1) x (m+1) to handle empty string cases easily
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {

      // If characters match (Note: strings are 0-indexed, so we check i-1)
      if (text1[i - 1] == text2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1]; // Diagonal + 1
      }
      // If characters don't match
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Max(Up, Left)
      }
    }
  }

  // The bottom-right cell contains the length of LCS
  return dp[n][m];
}

int main()
{
  string s1 = "ABCDE";
  string s2 = "ACE";

  cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;

  return 0;
}