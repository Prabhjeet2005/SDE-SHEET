#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{

public:
  string solution(vector<int> &gears)
  {
    for (int i = 0; i < gears.size(); i++)
    {
      for (int j = 0; j < gears.size(); j++)
      {
        swap(gears[i], gears[j]);
        for (auto &it : gears)
        {
          cout << it << ", ";
        }
        long long x = 0, y = 0;
        long double z = 1.0L;
        long double finalRPS = 1;
        for (int k = 1; k < gears.size(); k++)
        {
          x = gears[k];
          y = gears[k - 1];
          finalRPS = (y * z / x);
          z = finalRPS;
          cout<<"X: "<<x<<", Y: "<<y<<"Z: "<<z<<"\n";
        }
        cout<<"\nNEW\n";
        if (fabsl(z - 1.0L) < 1e-12L)
        {
          return "yes";
        }
        swap(gears[i], gears[j]);
      }
    }

    return "no";
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  vector<int> gears;
  int t;
  cin >> t;
  for (int j = 0; j < t; j++)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int element;
      cin >> element;
      gears.push_back(element);
    }
    string ans = sol.solution(gears);
    cout << ans << "\n";
  }

  cout << endl;
}