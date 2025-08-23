#include <iostream>
#include <vector>

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
      int start = arr[i][0];
      int end = arr[i][1];
      if (!ans.empty() && end <= ans.back()[1])
      {
        continue;
      }
      for (int j = i + 1; j < arr.size(); j++)
      {
        if (arr[j][0] <= end)
        {
          end = max(end, arr[j][1]);
        }
        else
        {
          break;
        }
      }
      ans.push_back({start, end});
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