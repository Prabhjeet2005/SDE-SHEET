#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  void swap(vector<int> &arr, int first, int second)
  {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }

public:
  void solution()
  {
    vector<int> arr = {2, 1, 3};
    int breakPoint = -1;
    for (int i = arr.size() - 1; i > 0; i--)
    {
      if (arr[i - 1] < arr[i])
      {
        breakPoint = i - 1;
        break;
      }
    }

    if (breakPoint == -1)
    {
      reverse(arr.begin(), arr.end());
      for (auto &it : arr)
      {
        cout << it << ", ";
      }
      return;
    }

    for (int i = arr.size() - 1; i > breakPoint; i--)
    {
      if (arr[breakPoint] < arr[i])
      {
        swap(arr, breakPoint, i);
        break;
      }
    }

    reverse(arr.begin() + breakPoint + 1, arr.end());
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