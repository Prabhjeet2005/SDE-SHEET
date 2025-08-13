#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;
    int maxSize = 0;
    int sum = arr[0];

    int left = 0, right = 0;
    while (right < arr.size())
    {
      while (left <= right && sum > k)
      {
        sum -= arr[left];
        left++;
      }
      if (sum == k)
      {
        maxSize = max(maxSize, right - left + 1);
      }
      right++;
      if (right < arr.size())
      {
        sum += arr[right];
      }
    }

    cout << "Max Subarray Length Equal K: " << maxSize << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}