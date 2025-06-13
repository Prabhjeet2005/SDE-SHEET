#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  vector<int> calculatePascalRow(int numRow)
  {
    long long val = 1;
    vector<int> ans;
    ans.push_back(val);
    for (int i = 1; i < numRow; i++)
    {
      val = val * (numRow - i) / i;
      ans.push_back(val);
    }
    return ans;
  }

public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> result;
    for (int i = 1; i <= numRows; i++)
    {
      result.push_back(calculatePascalRow(i));
    }
    return result;
  }
};
int main()
{
  Solution s = Solution();
  int numRows = 5;
  vector<vector<int>> ans = s.generate(numRows);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}