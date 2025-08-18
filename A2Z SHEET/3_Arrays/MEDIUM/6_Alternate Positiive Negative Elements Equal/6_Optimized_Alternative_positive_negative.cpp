#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    // vector<int> arr = {1, 2, -3, -1, -2, 3};
    vector<int> arr = {1, 2, -4, -5, 3, 4, 5, 6};
    int positive = 0;
    int negative = 0;
    int current = 0;
    vector<int> ans;

    while (positive < arr.size() && negative < arr.size())
    {
      while (positive < arr.size() && arr[positive] < 0)
      {
        positive++;
      }

      while (negative < arr.size() && arr[negative] > 0)
      {
        negative++;
      }

      if (current % 2 == 0)
      {
        ans.push_back(arr[positive]);
        positive++;
        current++;
      }
      else
      {
        ans.push_back(arr[negative]);
        negative++;
        current++;
      }
    }

    while (positive < arr.size() && arr[positive] >= 0)
    {
      ans.push_back(arr[positive]);
      positive++;
      current++;
    }
    while (negative < arr.size() && arr[negative] < 0)
    {
      ans.push_back(arr[negative]);
      negative++;
      current++;
    }

    for (auto &it : ans)
    {
      cout << it << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}