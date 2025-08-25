#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution
{

public:
  string solution(vector<int> &gears)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < gears.size(); i++)
    {
      map[gears[i]]++;
    }
    for (auto &it : map)
    {
      cout << it.first << ":" << it.second << ", ";
    }
    cout << "\n";
    int changed = 0;
    for (int i = 0; i < gears.size(); i++)
    {
      if (changed >= 2)
        break;
      if (map.find(gears[i]) != map.end())
      {
        if (gears[i] >= 2)
        {
          if (changed == 0)
          {
            cout << "\nArray: ";
            for (auto &it : gears)
            {
              cout << it << ", ";
            }
            cout << "\n";

            swap(gears[i], gears[0]);
            cout << "\nArray: ";
            for (auto &it : gears)
            {
              cout << it << ", ";
            }
            cout << "\n";
          }
          if (changed == 1)
          {
            swap(gears[gears.size() - 1], gears[i]);
            break;
          }
          changed++;
        }
      }
    }
    cout << "\nArray: ";
    for (auto &it : gears)
    {
      cout << it << ", ";
    }
    cout << "\n";

    long long x = 0,
              y = 0;
    long double z = 1.0L;
    long double finalRPS = 1;
    for (int k = 1; k < gears.size(); k++)
    {
      x = gears[k];
      y = gears[k - 1];
      finalRPS = (y * z / x);
      z = finalRPS;
      cout << "X: " << x << ", Y: " << y << "Z: " << z << "\n";
    }
    cout << "\nNEW\n";
    if (fabsl(z - 1.0L) < 1e-12L)
    {
      return "yes";
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