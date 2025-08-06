#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void selection_sort()
  {
    vector<int> arr = {1, 5, 6, 2, 8, 3, 3};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      int minIndex = i;
      for (int j = i + 1; j < n; j++)
      {
        if (arr[minIndex] > arr[j])
        {
          minIndex = j;
        }
      }
      swap(arr[i], arr[minIndex]);
    }
    for (auto it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.selection_sort();
  cout << endl;
}