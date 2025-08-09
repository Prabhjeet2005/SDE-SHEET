#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 0, 23, 4, 5, 0, 8, 0, 9, 0};
    int n = arr.size();

    int ptrZero = -1;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        ptrZero = i;
        break;
      }
    }

    if (ptrZero == -1)
    {
      cout << "No Zeroes Exist" << endl;
      return;
    }

    for (int j = ptrZero + 1; j < n; j++)
    {
      if (arr[j] != 0)
      {
        swap(arr[j], arr[ptrZero]);
        ptrZero++;
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