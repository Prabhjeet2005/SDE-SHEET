#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  int make_partition(vector<int> &arr, int beg, int end)
  {
    int pivotElement = arr[beg];
    int count = 0;

    for (int i = beg + 1; i <= end; i++)
    {
      if (arr[i] <= pivotElement)
      {
        count++;
      }
    }

    int pivotIndex = beg+count;
    swap(arr[beg], arr[pivotIndex]);

    int start = beg;
    int finish = end;

    while (start < pivotIndex && finish > pivotIndex)
    {
      while (arr[start] <= pivotElement)
      {
        start++;

      }
      while (arr[finish] > pivotElement)
      {
        finish--;

      }
      if (start < pivotIndex && finish > pivotIndex)
      {
        swap(arr[start++], arr[finish--]);
      }
    }
    return pivotIndex;
  }
  void quick_sort(vector<int> &arr, int beg, int end)
  {
    if (beg >= end)
    {
      return;
    }
    int partition = make_partition(arr, beg, end);
    quick_sort(arr, beg, partition - 1);
    quick_sort(arr, partition + 1, end);
  }

public:
  void solution()
  {
    vector<int> arr = {2, 2, 1, 0, 0, 1, 2};
    quick_sort(arr, 0, arr.size() - 1);

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}