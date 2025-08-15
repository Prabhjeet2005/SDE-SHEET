#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void swap(vector<int> &arr, int first, int second)
  {
    arr[first] = arr[first] + arr[second];
    arr[second] = arr[first] - arr[second];
    arr[first] = arr[first] - arr[second];
  }

public:
  void solution()
  {
    vector<int> arr = {2, 2, 1, 0, 0, 1, 2};
    int low = 0;
    int mid = 0;
    int high = arr.size();

    while (mid <= high)
    {
      if (arr[mid] == 0)
      {
        swap(arr, low, mid);
        low++;
        mid++;
      }
      else if (arr[mid] == 1)
      {
        mid++;
      }
      else if (arr[mid] == 2)
      {
        swap(arr, mid, high);
        high--;
      }
    }

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}