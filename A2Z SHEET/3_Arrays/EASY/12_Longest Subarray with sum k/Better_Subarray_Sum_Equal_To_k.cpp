#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;
    int sum = 0;
    int maxSize = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < arr.size(); i++)
    {
      sum += arr[i]; // Prefix Sum

      if (sum == k)
      {
        maxSize = max(maxSize, i - 0 + 1);
      }

      if (map.find(sum - k) != map.end())
      {
        maxSize = max(maxSize, i - map[sum - k]);
      }

      if (map.find(sum - k) == map.end())
      {
        map[sum] = i;
      }
    }
    cout << "Max Size Of Subarray with Sum K : " << maxSize << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}