#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = i; j < matrix[0].size(); j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    int size = matrix.size() - 1;
    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size() / 2; j++)
      {
        swap(matrix[i][j], matrix[i][size - j]);
      }
    }
  }
};

int main()
{
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution sol = Solution();
  sol.rotate(mat);
  for(auto i : mat){
    for(auto j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}
