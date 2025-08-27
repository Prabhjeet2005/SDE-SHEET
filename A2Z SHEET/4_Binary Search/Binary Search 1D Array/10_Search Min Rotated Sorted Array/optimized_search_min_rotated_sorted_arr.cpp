#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int start = 0, end = arr.size() - 1, minElement = INT_MAX;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[start] <= arr[mid])
      { // Left Half Sorted
        minElement = min(minElement, arr[start]);
        start = mid + 1;
      }
      else
      {// Right Half Sorted
        minElement = min(minElement, arr[mid]);
        end = mid - 1;
      }
    }
    cout << "Min Element: " << minElement;
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