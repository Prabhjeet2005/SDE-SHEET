// Given an m x n integer matrix matrix, if an element is 0, set its
// entire row and column to 0's.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  void setRowZero(vector<vector<int>> &matrix, int rowIndex, int rowSize)
  {
    for (int col = 0; col < rowSize; col++)
    {
      if (matrix[rowIndex][col] != 0)
        matrix[rowIndex][col] = -1;
    }
  }
  void setColZero(vector<vector<int>> &matrix, int colIndex, int colSize)
  {
    for (int row = 0; row < colSize; row++)
    {
      if (matrix[row][colIndex] != 0)
        matrix[row][colIndex] = -1;
    }
  }

public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    for (int i = 0; i < rowSize; i++)
    {
      for (int j = 0; j < colSize; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][j] = -1;
          setRowZero(matrix, i, rowSize);
          setColZero(matrix, j, colSize);
        }
      }
    }
    for (int i = 0; i < rowSize; i++)
    {
      for (int j = 0; j < colSize; j++)
      {
        if(matrix[i][j]==-1){
          matrix[i][j]=0;
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