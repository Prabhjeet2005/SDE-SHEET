#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int n1 = arr1.size(), n2 = arr2.size(), k = 4;
    int leftHalfSize = k;
    int start = max(0,k-n2), end = min(k,n1);
    long double ans = -1;

    while (start <= end)
    {
      int mid1 = start + (end - start) / 2; // Arr1 Left Half
      int mid2 = leftHalfSize - mid1;
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
        cout << "Kth element: " << max(l1, l2);
        return;
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

  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}