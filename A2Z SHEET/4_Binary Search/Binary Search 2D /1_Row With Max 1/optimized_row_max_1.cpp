#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int rowSize = arr.size(), colSize = arr[0].size();
    int maxCount = INT_MIN, ansRowIndex = -1;

    for (int row = 0; row < rowSize; row++)
    {
      int currentOne = 0;
      int start = 0, end = colSize - 1;
      while (start <= end)
      {
        int mid = start + (end - start) / 2;
        if (arr[row][mid] == 1)
        {
          currentOne = colSize - mid;
          end = mid - 1;
        }
        else
        {
          start = mid + 1;
        }
      }
      if (currentOne != 0 && currentOne > maxCount)
      {
        maxCount = currentOne;
        ansRowIndex = row;
      }
    }
    cout << "Row With Max 1's: " << ansRowIndex;
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