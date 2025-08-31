#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  long long ExpPowBase(int Base, int Power)
  {
    long long tempAns = 1;
    while (Power > 0)
    {
      if (Power % 2 == 1)
      {
        Power--;
        tempAns *= Base;
      }
      else
      {
        Power /= 2;
        Base = Base * Base;
      }
    }
    return tempAns;
  }

public:
  void solution()
  {
    int n = 3, m = 27;
    long long ans = -1;
    long long number = -1;

    for (int i = 1; i < m; i++)
    {
      ans = ExpPowBase(i, n);
      if (ans == m)
      {
        number = i;
        break;
      }
    }
    cout << "Nth Number : " << number;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}