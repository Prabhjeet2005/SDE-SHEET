#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void setMatrixZero(vector<vector<int>> &arr, vector<bool> &row, vector<bool> &col)
  {
    for (int rowIt = 0; rowIt < row.size(); rowIt++)
    {
      if (row[rowIt] == true)
      {
        for (int i = 0; i < col.size(); i++)
        {
          arr[rowIt][i] = 0;
        }
      }
    }
    for (int colIt = 0; colIt < col.size(); colIt++)
    {
      if (col[colIt] == true)
      {
        for (int i = 0; i < row.size(); i++)
        {
          arr[i][colIt] = 0;
        }
      }
    }
  }

public:
  void solution()
  {
    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<bool> row(arr.size(), 0);
    vector<bool> col(arr[0].size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr[0].size(); j++)
      {
        if (arr[i][j] == 0)
        {
          row[i] = true;
          col[j] = true;
          cout << "i & j : " << i << j << ", row[i]: " << row[i] << ", col[j]: " << col[j] << endl;
        }
      }
    }
    cout << "\n\nRow: ";
    for (int it = 0; it < row.size(); it++)
      cout << row[it] << ", ";
    cout << endl;
    cout << "col: ";
    for (int it = 0; it < row.size(); it++)
      cout << col[it] << ", ";

    cout << endl;
    setMatrixZero(arr, row, col);

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