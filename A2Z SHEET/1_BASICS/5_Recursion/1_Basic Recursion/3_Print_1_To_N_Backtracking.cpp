#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void solve(int end)
  {
    if (end<=0)
    {
      return;
    }
    solve(end-1);
    cout << end << ", ";  // BACKTRACKING
  }

public:
  void solution(int n)
  {
    solve(n);
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(5);
  cout << endl;
}