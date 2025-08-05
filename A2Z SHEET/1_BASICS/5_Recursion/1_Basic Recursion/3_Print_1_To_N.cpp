#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void solve(int current, int end)
  {
    if (current > end)
    {
      return;
    }
    cout << current << ", ";
    solve(current + 1, end);
  }

public:
  void solution(int n)
  {
    solve(1, n);
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(5);
  cout << endl;
}