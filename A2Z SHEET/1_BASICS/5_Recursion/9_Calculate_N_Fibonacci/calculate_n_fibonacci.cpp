#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  int get_nth_fibbonacci(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    if (n == 1)
    {
      return 1;
    }
    return get_nth_fibbonacci(n - 1) + get_nth_fibbonacci(n - 2);
  }

public:
  void solution()
  {
    int n = 7;
    int ans = 0;
    ans = get_nth_fibbonacci(n);
    cout << n << "th Fibonacci: " << ans << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}