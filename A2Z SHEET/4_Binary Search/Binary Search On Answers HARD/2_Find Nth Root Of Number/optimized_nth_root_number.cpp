#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution()
  {
    int n = 3, m = 27;
    long long ans = -1;

    int start = 1, end = m;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      long long midTimesN = 1;
      for (int i = 0; i < n; i++)
        midTimesN *= mid;
      if (midTimesN == m)
      {
        ans = mid;
        break;
      }
      else if (midTimesN > m)
        end = mid - 1;
      else
        start = mid + 1;
    }
    cout << "Nth Number : " << ans<<"\n" << ceil(2.5);
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