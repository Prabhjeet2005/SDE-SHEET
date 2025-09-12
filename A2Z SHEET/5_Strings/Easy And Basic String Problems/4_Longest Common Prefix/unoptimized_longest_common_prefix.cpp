#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<string> strs = {"flower", "flow", "flight"};
    int minStrSize = INT_MAX, cnt = 0;
    if (strs.size() == 1)
    {
      cout << strs[0];
      return;
    }
    string temp = "", ans = "";
    for (int i = 0; i < strs.size(); i++)
    {
      if (minStrSize > strs[i].size() - 1)
      {
        minStrSize = strs[i].size() - 1;
        temp = strs[i];
      }
    }

    for (int i = 0; i < strs.size(); i++)
    {
      for (int j = 0; j <= minStrSize; j++)
      {
        if (strs[i][j] != temp[j])
        {
          minStrSize = j - 1;
          temp = strs[i].substr(0, j);
        }
      }
    }
    if (minStrSize < 0)
      cout << "";

    cout << "Common Prefix: " << temp;
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