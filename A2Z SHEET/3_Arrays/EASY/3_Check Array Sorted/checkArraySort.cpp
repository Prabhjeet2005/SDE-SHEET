#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 4, 5, 6, 7, 7, 8, 9};
    bool isSorted = true;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        isSorted = false;
      }
    }

    if (isSorted)
    {
      cout << "Array is Sorted" << endl;
    }
    else
    {
      cout << "Array is Not Sorted" << endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}