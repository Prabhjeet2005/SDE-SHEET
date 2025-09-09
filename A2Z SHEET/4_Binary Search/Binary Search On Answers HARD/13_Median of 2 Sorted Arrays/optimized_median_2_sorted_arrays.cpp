#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3};
    int n1 = arr1.size(), n2 = arr2.size();
    int leftHalfSize = (n1 + n2 + 1 ) / 2;

    int start = 0, end = n1;
    long double ans = -1;
    while (start <= end)
    {
      int mid1 = start + (end - start) / 2; // No. of Array1 elements selected for left half
      int mid2 = leftHalfSize - mid1;       // No. of Array2 elements selected for left half

      int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
      if (mid1 - 1 >= 0 && mid1 - 1 < n1)
        l1 = arr1[mid1 - 1];
      if (mid2 - 1 >= 0 && mid2 - 1 < n2)
        l2 = arr2[mid2 - 1];
      if (mid1 >= 0 && mid1 < n1)
        r1 = arr1[mid1];
      if (mid2 >= 0 && mid2 < n2)
        r2 = arr2[mid2];

      if (l1 <= r2 && l2 <= r1)
      {
        if ((n1 + n2) % 2 == 0)
        {
          // EVEN
          ans = (long double)(max(l1, l2) + min(r1, r2)) / (long double)2;
          cout << "Median: " << ans;
          return;
        }
        else
        {
          // ODD
          ans = (long double)max(l1, l2);
          cout << "Median: " << ans;
          return;
        }
      }
      else if (l1 > r2)
      {
        end = mid1 - 1;
      }
      else
      {
        start = mid1 + 1;
      }
    }
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