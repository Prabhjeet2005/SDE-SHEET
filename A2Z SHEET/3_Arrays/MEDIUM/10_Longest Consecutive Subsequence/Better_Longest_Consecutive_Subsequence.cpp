#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void swap(vector<int> &arr, int firstElement, int secondElement)
  {
    int temp = arr[firstElement];
    arr[firstElement] = arr[secondElement];
    arr[secondElement] = temp;
  }

  int find_partition(vector<int> &arr, int start, int end)
  {
    int pivotElement = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
      if (arr[i] <= pivotElement)
      {
        count++;
      }
    }
    int pivotIndex = count + start;
    swap(arr, pivotIndex, start);

    int left = start, right = end;

    while (left < pivotIndex && right > pivotIndex)
    {
      while (arr[left] <= pivotElement)
      {
        left++;
      }
      while (arr[right] > pivotElement)
      {
        right--;
      }
      if (left < pivotIndex && right > pivotIndex)
      {
        swap(arr, left++, right++);
      }
    }
    return pivotIndex;
  }

  void quick_sort(vector<int> &arr, int start, int end)
  {
    if (start >= end)
    {
      return;
    }
    int partition = find_partition(arr, start, end);
    quick_sort(arr, start, partition - 1);
    quick_sort(arr, partition + 1, end);
  }

public:
  void solution()
  {
    vector<int> arr = {100, 200, 1, 3, 2, 4};

    quick_sort(arr, 0, arr.size() - 1);

    int longestSequence = 1;
    int currentSequence = 1;

    if (arr.size() <= 1)
    {
      cout << "Longest: " << longestSequence << endl;
    }

    for (int i = 0; i < arr.size() - 1; i++)
    {
      if (arr[i] + 1 == arr[i + 1])
      {
        currentSequence++;
        longestSequence = max(longestSequence, currentSequence);
      }
      else
      {
        currentSequence = 1;
      }
    }

    cout << "Longest Consecutive Sequence: " << longestSequence << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}