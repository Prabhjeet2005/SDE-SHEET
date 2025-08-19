#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int currentSum = arr[0];
    int countSubarray = 0;

    int left = 0, right = 0;
    while (right < arr.size())
    {
      while (left <= right && currentSum > k)
      {
        currentSum -= arr[left];
        left++;
      }
      if (currentSum == k)
      {
        countSubarray++;
      }
      right++;
      if (right < arr.size())
      {
        currentSum += arr[right];
      }
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