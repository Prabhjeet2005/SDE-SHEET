// Given an m x n integer matrix matrix, if an element is 0, set its
// entire row and column to 0's.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    vector<bool> row(rowSize);
    vector<bool> col(colSize);
    for (int i = 0; i < rowSize; i++)
    {
      for (int j = 0; j < colSize; j++)
      {
        if (matrix[i][j] == 0)
        {
          row[i] = true;
          col[j] = true;
        }
      }
    }
    for (int i = 0; i < rowSize; i++)
    {
      for (int j = 0; j < colSize; j++)
      {
        if (row[i] || col[j])
        {
          matrix[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < rowSize; i++)
    {
      for (int j = 0; j < colSize; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution s = Solution();
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  s.setZeroes(matrix);
}