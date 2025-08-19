#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    unordered_map<int,int> map;
    int currentSum = 0;
    int countSubarray = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      currentSum += arr[i];
      if (currentSum == k)
      {
        countSubarray++;
      }
      if (map[currentSum - k])
      {
        countSubarray+=map[currentSum-k];
      }
      map[currentSum]++;
    }

    cout << "Count Subarray Sum Equal K: " << countSubarray << endl;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}