/*
### ⚔️ Blind Story-Stripping Challenge 3

**Problem: The Quantum Crystals**
You are a physicist studying a newly discovered alien artifact. The artifact contains N quantum crystals arranged in a straight line, numbered from 0 to N-1. Each crystal continuously emits a specific energy signature, represented by an integer array E.
To unlock the artifact, you must input the correct energy readings for Q sequences. For each sequence, the artifact highlights a starting crystal L and an ending crystal R. The true combined energy of a sequence is not the sum, but rather the **Bitwise XOR** of all the crystal signatures from index L to index R (inclusive).
Return an array containing the correct combined energy answer for each of the Q sequences.
**Constraints:**
1 <= N <= 10^5
1 <= Q <= 10^5
0 <= L <= R < N
1 <= E[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {};
    vector<vector<int>> queries = {};
    int n = arr.size();
    vector<int> prefix_xor(n + 1, 0);
    int xor_arr = 0;
    for (int i = 1; i <= n; i++)
    {
      xor_arr ^= arr[i-1]; // HERE: 0 Based Arr IMPORTANT i FORGOT
      prefix_xor[i] = xor_arr;
    }

    vector<int> result(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++)
    {
      int l = queries[i][0];
      int r = queries[i][1];
      result[i] = prefix_xor[r + 1] ^ prefix_xor[l - 1 + 1];
    }

    for (auto &element : result)
    {
      cout << element << " ";
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