#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 2, 1, 0, 0, 1, 2};
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == 0)
      {
        zeroCount++;
      }
      if (arr[i] == 1)
      {
        oneCount++;
      }
      if (arr[i] == 2)
      {
        twoCount++;
      }
    }

    for (int i = 0; i < zeroCount; i++)
    {
      arr[i] = 0;
    }
    for (int i = zeroCount; i < zeroCount + oneCount; i++)
    {
      arr[i] = 1;
    }
    for (int i = zeroCount + oneCount; i < arr.size(); i++)
    {
      arr[i] = 2;
    }

    for (int &it : arr)
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