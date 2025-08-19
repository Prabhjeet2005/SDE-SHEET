#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  long long calculateFactorial(int number)
  {
    long long ans = 1;
    for (int i = number; i >= 2; i--)
    {
      ans *= i;
    }
    return ans;
  }

public:
  void solution()
  {
    int row = 5;
    vector<vector<int>> result;
    for (int j = 0; j < row; j++)
    {
      vector<int> finalAns;
      for (int i = 0; i < j+1; i++)
      {

        long long rowFactorial = calculateFactorial(j);
        long long colFactorial = calculateFactorial(i);
        long long rowMinusColFFactorial = calculateFactorial((j) - (i));

        long long ans = rowFactorial / (colFactorial * rowMinusColFFactorial);
        finalAns.push_back((int)ans);
      }
      result.push_back(finalAns);
    }

    for (auto &it : result)
    {
      for (auto &iterator : it)
      {
        cout << iterator << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  cout << endl;
  sol.solution();
  cout << endl;
}