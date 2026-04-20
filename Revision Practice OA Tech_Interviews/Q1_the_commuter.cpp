/*


### Problem Statement: The Mountain Mapper

You are an explorer navigating a 2D grid of elevations. You start at the top-left cell `(0, 0)` and you want to reach the bottom-right cell `(rows-1, cols-1)`.

In one move, you can go up, down, left, or right to an adjacent cell.

A route's **effort** is defined as the **maximum absolute difference** in elevation between *any* two consecutive cells on that route.

Your task is to return the **minimum effort** required to travel from the top-left corner to the bottom-right corner.

#### Constraints:
* `rows == heights.length`
* `cols == heights[i].length`
* 1 <= \text{rows, cols} <= 100
* 1 <= \text{heights}[i][j] <= 10^6

#### Example 1:
**Input:** `heights = [[1, 2, 2], [3, 8, 2], [5, 3, 5]]`
**Output:** `2`
**Explanation:** The route of `(0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2)` translates to elevations `[1, 3, 5, 3, 5]`.
The absolute differences between consecutive steps are `[|3-1|, |5-3|, |3-5|, |5-3|]` = `[2, 2, 2, 2]`.
The maximum difference on this path is `2`. Any other path has a maximum difference of `3` or higher.

#### Example 2:
**Input:** `heights = [[1, 2, 3], [3, 8, 4], [5, 3, 5]]`
**Output:** `3`
**Explanation:**
The best route is `(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)` which translates to `[1, 2, 3, 4, 5]`.
The absolute differences are `[1, 1, 1, 1]`. The maximum difference is `1`. Wait, looking at the grid: `(1,2)` is `4`, `(2,2)` is `5`. The difference between `(0,2)` which is `3` and `(1,2)` which is `4` is `1`.
*Correction:* In this specific grid, the path `[1, 2, 3, 4, 5]` gives a max difference of `1`.
Let's look at another path for the actual example 2 grid: `heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]`. If this was the grid, the output would be `0`.
*Stick to the provided grid above:* If you traverse `1 -> 2 -> 3 -> 4 -> 5`, the max difference is `1`. Let's assume the example output `3` was for a different path if `3` was blocked. For the sake of the algorithm, calculate the absolute minimum mathematically possible.


*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
  int n, m;

public:
  void solution()
  {
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    n = heights.size(), m = heights[0].size();
    int ans = dijkstra(heights);
    cout << ans;
  }

private:

  struct CustomDS{
    int distance;
    int row;
    int col;
  };

  struct CustomCompare{
    bool operator()(CustomDS a,CustomDS b){
      return a.distance > b.distance; // Min Heap
    }
  };

  int dijkstra(vector<vector<int>> &heights)
  {
    vector<vector<int>>dist(n+1,vector<int>(m+1,1e9));

    // {distance, {row,col}}
    priority_queue<CustomDS,vector<CustomDS>,CustomCompare>pq;
    dist[0][0] = true;
    pq.push({0, 0 ,0});

    // DLRU
    vector<int> dr = {1, 0, 0, -1};
    vector<int> dc = {0, -1, 1, 0};

    while (!pq.empty())
    {
      CustomDS top = pq.top();
      int distance = top.distance ,row = top.row, col = top.col;
      pq.pop();

      if(row == n-1 && col == n-1)return distance;

      if(distance > dist[row][col])continue;

      for (int i = 0; i < 4; i++)
        {
          int new_row = row + dr[i];
          int new_col = col + dc[i];

          if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= m)
            continue;

          if (abs(heights[row][col] - heights[new_row][new_col]) < distance){
            dist[new_row][new_col] = dist[row][col] + heights[new_row][new_col];
            pq.push({abs(heights[row][col] - heights[new_row][new_col]), new_row, new_col});
          }
         
      }
    }

    return 1e9;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}