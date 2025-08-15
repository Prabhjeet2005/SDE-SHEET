#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
      if (map.find(target - arr[i]) != map.end())
      {
        ans[0] = map[target - arr[i]];
        ans[1] = i;
        ansString = "YES";
      }

      if (map.find(arr[i]) == map.end())
      {
        map[arr[i]] = i;
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