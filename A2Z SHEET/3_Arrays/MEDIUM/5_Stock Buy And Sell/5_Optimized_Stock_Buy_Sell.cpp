#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int minElement = INT_MAX;
    int maxProfit = 0;
    int currentProfit = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] < minElement)
      {
        minElement = arr[i];
      }
      currentProfit = arr[i] - minElement;
      maxProfit = max(maxProfit, currentProfit);
    }

    cout << "Max Profit: " << maxProfit << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}