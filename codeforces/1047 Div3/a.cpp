#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution(int k, int x)
  {
    int ans = -1;
    for (int i = 1; i <=1e5 ; i++)
    {
      int initial = i;
      for (int j = 1; j <= k; j++)
      {
        if (initial % 2 == 0)
        {
          initial /= 2;
        }
        else
        {
          initial = 3 * initial + 1;
        }
      }

      if (initial == x)
      {
        ans = i;
        cout << ans;
        return;
      }
    }
  }
};
// 3 1 4 1 5 5 4
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solObj = Solution();
  cout << "\n";
  int testcase, x, k;
  cin >> testcase;
  while (testcase != 0)
  {
    cin >> k >> x;
    solObj.solution(k, x);
    testcase--;
    cout << "\n";
  }
}