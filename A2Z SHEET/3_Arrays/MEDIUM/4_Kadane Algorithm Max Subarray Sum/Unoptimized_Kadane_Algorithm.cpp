#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int startIndex = -1;
    int endIndex = -1;
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      currentSum = 0;
      for (int j = i; j < arr.size(); j++)
      {
        currentSum += arr[j];
        maxSum = max(maxSum, currentSum);
        if (currentSum == maxSum)
        {
          startIndex = i;
          endIndex = j;
        }
      }
    }

    cout << "Max Subarray Sum: " << maxSum << endl;
    for (int i = startIndex; i <= endIndex; i++)
    {
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}