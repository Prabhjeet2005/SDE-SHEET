#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans;
    // Custom Sort by 0th element
    if (arr.size() == 1)
    {
      return;
    }
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    for (int i = 0; i < arr.size(); i++)
    {
      if (ans.empty())
      {
        ans.push_back(arr[i]);
        continue;
      }
      int start = arr[i][0];
      int end = arr[i][1];
      if (start <= ans.back()[1])
      {
        ans.back()[1] = max(end, ans.back()[1]);
      }
      else
      {
        ans.push_back({start, end});
      }
    }

    for (auto &array : ans)
    {
      cout << "{";
      for (auto &element : array)
      {
        cout << element << ",";
      }
      cout << "}, ";
    }
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