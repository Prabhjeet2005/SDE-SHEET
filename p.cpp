#include <iostream>
#include <vector>

using namespace std;

/*
The Problem: Minimum Cost Job Assignment
There are N workers and N tasks (N <= 10). You are given an N x N matrix where cost[i][j] is the cost of assigning worker i to task j. Assign exactly one task to each worker to minimize the total cost.
*/
// OUTPUT: 5

int N;
vector<vector<int>> cost_matrix;
int dp[3][];  

int solve(int mask, int curr_worker)
{

  if (curr_worker == N)
    return 0;

  if (dp[curr_worker][mask] != -1)
    return dp[curr_worker][mask];

  int min_cost = 1e9;
  for (int i = 0; i < N; i++)
  {
    // Check set
    if ((mask & (1 << i)) == 0)
    {
      int new_mask = mask | (1 << i);
      int curr_cost = cost_matrix[curr_worker][i];
      int new_cost = curr_cost + solve(new_mask, curr_worker + 1);
      min_cost = min(min_cost, new_cost);
    }
  }

  return dp[curr_worker][mask] = min_cost;
}

int main()
{
  N = 3; // 3 Workers, 3 Tasks
  cost_matrix = {
      {3, 2, 7}, // Worker 0's cost for tasks 0, 1, 2
      {1, 5, 8}, // Worker 1's cost for tasks 0, 1, 2
      {9, 4, 2}  // Worker 2's cost for tasks 0, 1, 2
  };  
  // O/P: 5


  for (int i = 0; i < N; i++)
    for (int j = 0; j < 32; j++)
      dp[i][j] = -1;

  cout << "Min Cost: " << solve(0, 0);
}