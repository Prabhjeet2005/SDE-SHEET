#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    int start = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0);
    int minimizedLargestSum = 0;
    for (int limit = start; limit <= end; limit++)
    {
      int currentSum = 0, subarrayCount = 1;
      for (int i = 0; i < arr.size(); i++)
      {
        if (currentSum + arr[i] > limit)
        {
          subarrayCount++;
          currentSum = arr[i];
        }
        else
        {
          currentSum += arr[i];
        }
      }
      if (subarrayCount == k)
      {
        minimizedLargestSum = limit;
        break;
      }
    }
    cout << "Minimized Largest Sum: " << minimizedLargestSum;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}