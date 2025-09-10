#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
  int countSmallerEqualMid(vector<vector<int>> &arr, int mid)
  {
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      int start = 0, end = arr[0].size() - 1, ansIndex = -1;
      while (start <= end)
      {
        int middle = start + (end - start) / 2;
        if (arr[i][middle] <= mid)
        {
          ansIndex = middle;
          start = middle + 1;
        }
        else
        {
          end = middle - 1;
        }
      }
      count += ansIndex + 1;
    }
    return count;
  }

public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 2, 3, 4, 5},
                               {8, 9, 11, 12, 13},
                               {21, 23, 25, 27, 29}};

    int start = INT_MAX, end = INT_MIN, target = (arr.size() * arr[0].size()) / 2;

    for (int i = 0; i < arr.size(); i++)
    {
      start = min(start, arr[i][0]);
      end = max(end, arr[i][arr[0].size() - 1]);
    }
    int ans = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      int smaller = countSmallerEqualMid(arr, mid);
      if (smaller > target) // Find Smallest For target
      {
        ans = mid;
        end = mid - 1;
      }
      else
        start = mid + 1;
    }
    cout << "Median: " << ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}