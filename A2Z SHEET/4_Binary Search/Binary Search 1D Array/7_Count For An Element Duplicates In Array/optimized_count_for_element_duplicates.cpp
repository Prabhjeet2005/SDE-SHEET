#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void find_last(vector<int> &arr, int start, int end, int &last, int target)
  {
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] == target)
      {
        last = mid;
        start = mid + 1;
      }
      else if (arr[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
  }
  void find_first(vector<int> &arr, int start, int end, int &first, int target)
  {
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] == target)
      {
        first = mid;
        end = mid - 1;
      }
      else if (arr[mid] > target)
      {
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
    vector<int> arr = {1, 1, 2, 2, 2, 2, 2, 3};
    int target = 2;
    int start = 0, end = arr.size() - 1, first = -1, last = -1, countDuplicate = -1;
    find_first(arr, start, end, first, target);
    find_last(arr, start, end, last, target);
    countDuplicate = last - first + 1;
    cout << "Duplicate Count Of Target Element: " << countDuplicate;
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