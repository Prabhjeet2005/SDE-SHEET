#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void bubble_sort()
  {
    vector<int> arr = {1, 5, 6, 2, 8, 3, 3};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      bool flag = false;
      for (int j = 0; j < n - i - 1; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          swap(arr[j], arr[j + 1]);
          flag = true;
        }
      }
      for (auto &it : arr)
      {
        cout << it << ", ";
      }
      cout << endl;
      if (!flag)
      {
        break;
      }
    }
    cout << "Sorted List: ";
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
  sol.bubble_sort();
  cout << endl;
}