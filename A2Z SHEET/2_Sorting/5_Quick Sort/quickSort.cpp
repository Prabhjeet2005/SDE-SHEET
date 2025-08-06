#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  int partition(vector<int> &arr, int low, int high)
  {
    int pivotElement = arr[low];
    int pivotIndex = low;
    for (int i = low + 1; i <= high; i++)
    {
      if (arr[i] <= pivotElement)
      {
        pivotIndex++;
      }
    }
    swap(arr[low], arr[pivotIndex]);

    int left = low, right = high;

    while (left < pivotIndex && right > pivotIndex)
    {
      while (arr[left] < arr[pivotIndex])
      {
        left++;
      }
      while (arr[right] > arr[pivotIndex])
      {
        right--;
      }
      if (left < pivotIndex && right > pivotIndex)
      {
        swap(arr[left++], arr[right--]);
      }
    }
    return pivotIndex;
  }
  void quick_sort_algorithm(vector<int> &arr, int low, int high)
  {
    if (low >= high)
    {
      return;
    }
    int partitionElement = partition(arr, low, high);
    quick_sort_algorithm(arr, low, partitionElement - 1);
    quick_sort_algorithm(arr, partitionElement + 1, high);
  }

public:
  void quick_sort()
  {
    vector<int> arr = {1, 8, 3, 56, 3, 9, 4};
    int n = arr.size();
    quick_sort_algorithm(arr, 0, n - 1);

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.quick_sort();
  cout << endl;
}