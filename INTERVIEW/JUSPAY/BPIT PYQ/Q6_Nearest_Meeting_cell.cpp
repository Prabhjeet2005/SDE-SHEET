/*
Nearest Meeting Cell
Problem Statement:
You are given a maze with N cells. Each cell may have multiple entry points but not more
than one exit (i.e. edges are unidirectional).
The cells are numbered from 0 to N-1.
You are given an array Edge[] where:
●
●
Edge[i] contains the cell reachable from cell i
Edge[i] = -1 means there is no exit from cell i
Given two cells C1 and C2, find the nearest meeting cell that can be reached from both cells.
If multiple such cells exist, return the one with the smallest index.
If no meeting cell exists, return -1.
Constraints:
●
1 <= N <= 10^5
Input Format:
●
●
●
First line: Integer N
Second line: N integers representing Edge[]
Third line: Two integers C1 and C2
Output Format:
Print a single integer representing the nearest meeting cell.
Sample Input:
23
9 2
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
Sample Output:
4
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Only 1 EXIT so No need for Adj_List

void bfs(int src, vector<int> &arr, vector<int> &dist)
{
  queue<int> q;
  dist[src] = 0;
  q.push(src); // FIX: Put src first

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    int neighbor = arr[front];
    // Exit allowed and Unvisited
    if (neighbor != -1 && dist[neighbor]==1e9)
    {
      dist[neighbor] = dist[front] + 1;
      q.push(neighbor);
    }
  }
}

int solution(int src1, int src2, vector<int> &arr)
{
  int n = arr.size();
  vector<int> dist1(n + 1, 1e9), dist2(n + 1, 1e9);

  bfs(src1, arr, dist1);
  bfs(src2, arr, dist2);

  int nearest_meeting_cell = 1e9,idx=-1;
  for (int i = 0; i < n; i++)
  {
    // != 1e9 is visited array tracking
    if (dist1[i] != 1e9 && dist2[i] != 1e9)
    {
      int max_time = max(dist1[i], dist2[i]);
      if (max_time < nearest_meeting_cell)
      {
        nearest_meeting_cell = max_time;
        idx = i;
      }
    }
  }
  return idx;
}

int main()
{
  int src1 = 9, src2 = 2;
  vector<int> arr = {4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21};

  cout << "\n"
       << solution(src1, src2, arr) << "\n";
}