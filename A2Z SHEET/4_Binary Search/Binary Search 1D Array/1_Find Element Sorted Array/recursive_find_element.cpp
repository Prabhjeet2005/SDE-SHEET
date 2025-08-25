#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void binarySearch(vector<int> &arr, int start, int end, int target, bool &found)
  {
    if (start > end)
    {
      return;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      found = true;
      return;
    }
    else if (arr[mid] > target)
    {
      binarySearch(arr, start, mid - 1, target, found);
    }
    else if (arr[mid] < target)
    {
      binarySearch(arr, mid + 1, end, target, found);
    }
  }

public:
  void solution()
  {
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int start = 0, end = arr.size() - 1;
    bool found = false;
    binarySearch(arr, start, end, target, found);
    if (found)
    {
      cout << "Element Found";
    }
    else
    {
      cout << "Element Not Found";
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