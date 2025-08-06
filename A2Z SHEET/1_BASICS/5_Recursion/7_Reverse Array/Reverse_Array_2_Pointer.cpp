#include <iostream>
#include<array>
using namespace std;

class Solution
{
public:
  void solution()
  {
    array<int,5> arr = {1, 2, 3, 4, 5};

    int start = 0;
    int end = arr.size() - 1;

    for (int i = 0; i < arr.size() / 2 ; i++)
    {
      arr[i] = arr[i] + arr[end - i];
      arr[end - i] = arr[i] - arr[end - i];
      arr[i] = arr[i] - arr[end - i];
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
