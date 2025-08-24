#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void merge(vector<int> &arr, int low, int mid, int high, int &count)
  {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left++]);
      }
      else
      {
        temp.push_back(arr[right++]);
        count += (mid - left + 1);
      }
    }
    while (left <= mid)
    {
      temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
      temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
  }
  void merge_sort(vector<int> &arr, int low, int high, int &count)
  {
    if (low >= high)
    {
      return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid, count);
    merge_sort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
  }

public:
  void solution()
  {
    vector<int> arr = {5, 3, 2, 1, 4}; // 7
    int count = 0;
    merge_sort(arr, 0, arr.size() - 1, count);
    cout << "Count Inversion Pairs: " << count << "\n";
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