#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 0;
    int start = 0, end = arr.size() - 1, ans = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] == target)
      {
        ans = mid;
        break;
      }
      if (arr[start] <= arr[mid])
      {
        if (arr[start] <= target && target <= arr[mid])
        {
          end = mid - 1;
        }
        else
        {
          start = mid + 1;
        }
      }
      else
      {
        if (arr[mid] <= target && target <= arr[end])
        {
          start = mid + 1;
        }
        else
        {
          end = mid - 1;
        }
      }
    }
    cout << "Element Found at Index: " << ans;
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