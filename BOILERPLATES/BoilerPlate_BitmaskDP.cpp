#include <iostream>
#include <vector>

using namespace std;

/*
The Problem: Minimum Cost Job Assignment
There are N workers and N tasks (N <= 10). You are given an N x N matrix where cost[i][j] is the cost of assigning worker i to task j. Assign exactly one task to each worker to minimize the total cost.
*/

int N;
vector<vector<int>> cost_matrix;
vector<vector<int>> dp;

int solve(int mask, int curr_worker, int min_cost_total)
{
  if (curr_worker == N)
    return 0;

  int curr_cost = 1e9;
  for (int i = 0; i < N; i++)
  {
    // Check Not set
    if ((mask & (1 << i)) == 0)
    {
      int new_mask = mask | (1 << i);
      int new_cost = cost_matrix[curr_worker][i];
      int total_cost = new_cost + solve(new_mask, curr_worker + 1, min_cost_total);

      min_cost_total = min(min_cost_total, total_cost);
    }
  }

  return dp[curr_worker][mask] = min_cost_total;
}

int main()
{
  N = 3; // 3 Workers, 3 Tasks
  cost_matrix = {
      {3, 2, 7}, // Worker 0's cost for tasks 0, 1, 2
      {1, 5, 8}, // Worker 1's cost for tasks 0, 1, 2
      {9, 4, 2}  // Worker 2's cost for tasks 0, 1, 2
  };

  dp.resize(N+1, vector<int>(10, 1e9)); // 2^N
  // solve(mask, curr_worker,min_cost_total)
  cout << "Min cost: " << solve(0, 0, 1e9) << "\n";
}