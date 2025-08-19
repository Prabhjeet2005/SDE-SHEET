#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void setMarixZero(vector<vector<int>> &arr, int row, int col)
  {
    for (int i = 0; i < arr[0].size(); i++)
    {
      if (arr[row][i] == 0)
      {
        continue;
      }
      arr[row][i] = -1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i][col] == 0)
      {
        continue;
      }

      arr[i][col] = -1;
    }
  }

public:
  void solution()
  {
    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr[0].size(); j++)
      {
        if (arr[i][j] == 0)
        {
          setMarixZero(arr, i, j);
        }
      }
    }

    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr[0].size(); j++)
      {
        if (arr[i][j] == -1)
        {
          arr[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr[0].size(); j++)
      {
        cout << arr[i][j] << ", ";
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