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
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = i + 1; j < arr.size(); j++)
      {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
          ans = {i, j};
          ansString = "YES";
          break;
        }
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