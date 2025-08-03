#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int factorial(int n)
  {
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
      ans *= i;
    }
    return ans;
  }
  int nCr(int n, int r)
  {
    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n - r);

    return nfact / (rfact * nrfact);
  }

public:
  void pascalTriangleRow(int row)
  {
    cout << 1 << " ";
    if (row >= 2)
    {

      for (int i = 2; i < row; i++)
      {
        cout << nCr(row - 1, i - 1) << " ";
      }
      cout << 1 << endl;
    }
  }
};

int main()
{
  Solution s = Solution();
  int row = 5;
  s.pascalTriangleRow(row);
}
