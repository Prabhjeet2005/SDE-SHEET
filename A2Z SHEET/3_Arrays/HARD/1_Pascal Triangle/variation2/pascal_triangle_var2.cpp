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
    vector<int> finalAns;

    for (int i = 0; i < row; i++)
    {

      long long rowFactorial = calculateFactorial(row - 1);
      long long colFactorial = calculateFactorial(i);
      long long rowMinusColFFactorial = calculateFactorial((row - 1) - (i));

      long long ans = rowFactorial / (colFactorial * rowMinusColFFactorial);
      finalAns.push_back((int)ans);
    }

    for (auto &it : finalAns)
    {
      cout << it << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  cout << endl;
  sol.solution();
  cout << endl;
}