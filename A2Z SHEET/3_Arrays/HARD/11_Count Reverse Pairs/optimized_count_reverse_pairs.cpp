#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void count_pairs(vector<int> &arr, int start, int mid, int end, int &count)
  {
    int left = start, right = mid + 1;

    for(int left = start; left <= mid;  left++) // Put All left even after right finishes
    {
      while (right <= end && arr[left] > 2 * arr[right])
      {
        right++;
      }
      count += (right - (mid + 1) );
    }
  }
  void merge(vector<int> &arr, int start, int mid, int end)
  {
    vector<int> temp;
    int left = start, right = mid + 1;

    while (left <= mid && right <= end)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left++]);
      }
      else
      {
        temp.push_back(arr[right]);
        right++;
      }
    }
    while (left <= mid)
    {
      temp.push_back(arr[left++]);
    }
    while (right <= end)
    {
      temp.push_back(arr[right++]);
    }

    for (int i = start; i <= end; i++)
    {
      arr[i] = temp[i - start];
    }
  }
  void merge_sort(vector<int> &arr, int start, int end, int &count)
  {
    if (start >= end)
    {
      return;
    }
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid, count);
    merge_sort(arr, mid + 1, end, count);
    count_pairs(arr, start, mid, end, count);
    merge(arr, start, mid, end);
  }

public:
  void solution()
  {
    vector<int> arr = {2, 4, 3, 5, 1}; // 3
    int count = 0;
    merge_sort(arr, 0, arr.size() - 1, count);
    cout << "Count: " << count << "\n";
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