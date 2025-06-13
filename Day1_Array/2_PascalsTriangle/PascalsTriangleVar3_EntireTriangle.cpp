#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  long long factorial(int n)
  {
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
      result *= i;
    }
    return result;
  }
  int nCr(int n, int r)
  {
    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n - r);
    return nfact / (rfact * nrfact);
  }
  vector<int>
  calculatePascalRow(int numRow)
  {
    vector<int> pascalRow;
    pascalRow.push_back(1);
    if (numRow >= 2)
    {
      for (int i = 2; i < numRow; i++)
      {
        long long pascalElement = nCr(numRow - 1, i - 1);
        pascalRow.push_back(pascalElement);
      }
      pascalRow.push_back(1);
    }
    return pascalRow;
  }

public:
  vector<vector<int>> pascalTriangleEntire(int numRows)
  {
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
      vector<int> rowAns = calculatePascalRow(i);
      ans.push_back(rowAns);
    }
    return ans;
  }
};

int main()
{
  Solution s = Solution();
  int numRows = 5;
  vector<vector<int>> ans = s.pascalTriangleEntire(numRows);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}