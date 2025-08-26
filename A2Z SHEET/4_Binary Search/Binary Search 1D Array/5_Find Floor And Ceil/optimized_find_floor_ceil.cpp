#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void find_floor(vector<int> &arr, int start, int end, int &floor, int target)
  {
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] <= target)
      {
        floor = arr[mid];
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
  }
  void find_ceil(vector<int> &arr, int start, int end, int &ceil, int target)
  {
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] >= target)
      {
        ceil = arr[mid];
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
  }

public:
  void solution()
  {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;
    int start = 0, end = arr.size() - 1, floor = -1, ceil = -1;
    find_ceil(arr, start, end, ceil, target);
    find_floor(arr, start, end, floor, target);
    cout << "Floor: " << floor << "\nCeil: " << ceil;
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