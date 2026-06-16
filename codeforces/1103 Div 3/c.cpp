#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int find_min_op(int a, int b, int x)
{
  if (a == b)
  {
    return 1;
  }
  if (a < 0 || b < 0)
    return 0;

  if (dp[a][b] != -1)
    return dp[a][b];

  int add = min(find_min_op(a + 1, b, x), find_min_op(a, b + 1, x));
  int divide = min(find_min_op(a / x, b, x), find_min_op(a, b / x, x));

  return dp[a][b] = min(add, divide);
}

int solution(int a, int b, int x)
{
  dp.resize(a + 1, vector<int>(b + 1, -1));

  int min_op = -1;
  if (a == b)
    return 0;
  min_op = find_min_op(a, b, x);
  return min_op;
}

int main()
{
  int a, b, x;
  cin >> a;
  cin >> b;
  cin >> x;

  cout << solution(a, b, x);
}