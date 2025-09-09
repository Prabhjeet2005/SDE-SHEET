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
      int countOne = 0;
      for (int col = colSize - 1; col >= 0; col--)
      {
        if (arr[row][col] != 1)
          break;
        countOne++;
      }
      if (countOne != 0 && countOne > maxCount)
      {
        ansRowIndex = row;
        maxCount = countOne;
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