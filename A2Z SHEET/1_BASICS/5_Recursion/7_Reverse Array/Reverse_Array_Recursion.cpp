#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Solution
{
  void solve(array<int, 5> &arr, int i)
  {
    if (i >= arr.size() / 2)
    {
      return;
    }
    swap(arr[i], arr[arr.size() - i - 1]);
    solve(arr, i + 1);
  }

public:
  void solution()
  {
    auto n = 5;
    array<int, 5> arr = {1, 2, 3, 4, 5};
    solve(arr, 0);

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