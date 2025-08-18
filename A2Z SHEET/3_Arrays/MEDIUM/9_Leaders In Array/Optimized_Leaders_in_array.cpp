#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 7, 1, 0};
    int maxi = INT_MIN;
    vector<int> ans;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
      if (arr[i] <= maxi)
      {
        continue;
      }
      maxi = arr[i];
      ans.push_back(arr[i]);
    }

    for (auto &it : ans)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}