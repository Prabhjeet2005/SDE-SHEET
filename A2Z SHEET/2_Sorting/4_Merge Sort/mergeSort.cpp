#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> ans;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
      if (arr[left] < arr[right])
      {
        ans.push_back(arr[left++]);
      }
      else
      {
        ans.push_back(arr[right++]);
      }
    }

    while (left <= mid)
    {
      ans.push_back(arr[left++]);
    }

    while (right <= high)
    {
      ans.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
      arr[i] = ans[i - low];
    }
  }
  void merge_sort(vector<int> &arr, int low, int high)
  {
    if (low >= high)
    { // Only 1 Element Remain
      return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }

public:
  void solution()
  {
    vector<int> arr = {3, 2, 8, 5, 1, 4, 23};
    merge_sort(arr, 0, arr.size() - 1);

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}