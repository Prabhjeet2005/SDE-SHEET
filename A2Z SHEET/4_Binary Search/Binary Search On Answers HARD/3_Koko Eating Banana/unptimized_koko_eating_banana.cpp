#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {7, 15, 6, 3};
    int targetHours = 8;
    int minK = -1, maxElement = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
      maxElement = max(maxElement, arr[i]);
    }

    for (int i = 1; i <= maxElement; i++)
    {
      int currentSum = 0;
      for (int j = 0; j < arr.size(); j++)
      {
        currentSum += ceil((double)arr[j] / (double)i); // doule important
      }
      if (currentSum <= targetHours)
      {
        minK = i;
        break;
      }
    }
    cout << "Min K To Eat Banana: " << minK;
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