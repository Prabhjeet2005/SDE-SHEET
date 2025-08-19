#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    int startRow = 0, endRow = arr.size() - 1, startCol = 0, endCol = arr[0].size() - 1;

    while (startRow < endRow)
    {
      for (int i = startCol; i <= endCol; i++)
      {
        cout << arr[startRow][i] << ", ";
      }
      startRow++;
      for (int i = startRow; i <= endRow; i++)
      {
        cout << arr[i][endCol] << ", ";
      }
      endCol--;

      for (int i = endCol; i >= startCol; i--)
      {
        cout << arr[endRow][i] << ", ";
      }
      endRow--;
      for (int i = endRow; i >= startRow; i--)
      {
        cout << arr[i][startCol] << ", ";
      }
      startCol++;
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}