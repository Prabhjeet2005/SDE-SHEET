#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9};
    int n = 9;

    int xorN = 0;
    int xorArr = 0;

    for (int i = 1; i <= n; i++)
    {
      xorN ^= i;
    }

    for (int i = 0; i < n; i++)
    {
      xorArr ^= arr[i];
    }

    int missingNumber = xorN ^ xorArr;
    cout << "Missing Number: " << missingNumber << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}