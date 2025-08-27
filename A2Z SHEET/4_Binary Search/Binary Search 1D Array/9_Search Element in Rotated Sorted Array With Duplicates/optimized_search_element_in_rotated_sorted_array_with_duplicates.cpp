#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
    int target = 3;
    int start = 0, end = arr.size() - 1;
    bool ans = false;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] == target)
      {
        ans = true;
        break;
      }
      if (arr[start] == arr[mid] && arr[mid] == arr[target])
      {
        start++;
        end--;
        continue;
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
    cout << "Element Found " << ans;
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