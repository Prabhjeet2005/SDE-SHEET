#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = {-1, -1};
    string ansString = "NO";

    sort(arr.begin(), arr.end());
    int beginning = 0;
    int end = arr.size() - 1;

    while (beginning < end)
    {
      int sum = arr[beginning] + arr[end];
      if (sum == target)
      {
        ans[0] = arr[beginning];
        ans[1] = arr[end];
        ansString = "Yes";
        break;
      }

      else if (sum < target)
      {
        beginning++;
      }
      else if (sum > target)
      {
        end--;
      }
    }

    cout << "2 Sum Pair: { " << ans[0] << " , " << ans[1] << " }\n";
    cout << "2 Sum Exists: " << ansString;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();

  cout << endl;
}