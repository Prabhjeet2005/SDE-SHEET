#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  void reverse(vector<int> &arr, int start, int end)
  {
    while (start < end)
    {
      arr[start] = arr[start] + arr[end];
      arr[end] = arr[start] - arr[end];
      arr[start] = arr[start] - arr[end];
      start++;
      end--;
    }
  }

public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string leftOrRight = "right";

    if (leftOrRight == "left")
    {
      reverse(arr, 0, k);
      reverse(arr, k + 1, arr.size() - 1);
      reverse(arr, 0, arr.size() - 1);
    }
    else
    {
      reverse(arr, arr.size() - k, arr.size() - 1);
      reverse(arr, 0, arr.size() - k - 1);
      reverse(arr, 0, arr.size() - 1);
    }

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
}