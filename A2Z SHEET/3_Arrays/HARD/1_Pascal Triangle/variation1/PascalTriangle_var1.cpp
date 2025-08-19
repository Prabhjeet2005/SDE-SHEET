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
    int row = 1, col = 1;
    long long rowFactorial = calculateFactorial(row - 1);
    long long colFactorial = calculateFactorial(col - 1);
    long long rowMinusColFFactorial = calculateFactorial((row - 1) - (col - 1));
    cout << "Row Fact: " << rowFactorial << endl;
    cout << "Col Fact: " << colFactorial << endl;
    cout << "rowMinusColFFactorial: " << rowMinusColFFactorial << endl;

    long long ans = rowFactorial / (colFactorial * rowMinusColFFactorial);
    cout << "Pascal Triangle Element : " << ans;
  }
};

int main()
{
  Solution sol = Solution();
  cout << endl;
  sol.solution();
  cout << endl;
}