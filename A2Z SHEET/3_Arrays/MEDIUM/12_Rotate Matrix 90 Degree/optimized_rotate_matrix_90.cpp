#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void swapDiagonal(vector<vector<int>> &arr, int firstElement, int secondElement)
  {
    int temp = arr[firstElement][secondElement];
    arr[firstElement][secondElement] = arr[secondElement][firstElement];
    arr[secondElement][firstElement] = temp;
  }

  void swapSameRow(vector<vector<int>> &arr, int row, int col1, int col2)
  {
    int temp = arr[row][col1];
    arr[row][col1] = arr[row][col2];
    arr[row][col2] = temp;
  }

  void reverse(vector<vector<int>> &arr, int row)
  {
    int start = 0, end = arr[0].size() - 1;

    while (start < end)
    {
      swapSameRow(arr, row, start++, end--);
    }
  }

public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int row = 0; row < arr.size(); row++)
    {
      for (int col = row; col < arr[0].size(); col++)
      {
        swapDiagonal(arr, row, col);
      }
    }

    for (int row = 0; row < arr.size(); row++)
    {
      reverse(arr, row);
    }

    for (auto &it : arr)
    {
      for (auto &col : it)
      {
        cout << col << ", ";
      }
      cout << endl;
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