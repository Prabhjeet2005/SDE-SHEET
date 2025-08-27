#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4,5,1,2,3};
    int start = 0, end = arr.size() - 1, minElement = INT_MAX,countRotated=0;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[start] <= arr[mid])
      { // Left Half Sorted
        minElement = min(minElement, arr[start]);
        if(minElement == arr[start])countRotated = mid;
        start = mid + 1;
      }
      else
      { // Right Half Sorted
        minElement = min(minElement, arr[mid]);
        if(minElement == arr[mid])countRotated = mid;
        end = mid - 1;
      }
    }
    cout << "Count Rotated: " << countRotated;
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