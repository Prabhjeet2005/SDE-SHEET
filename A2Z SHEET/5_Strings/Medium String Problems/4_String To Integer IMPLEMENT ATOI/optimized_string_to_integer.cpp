#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    string str = "    -24876t47982";
    int index = 0;
    long long ans = 0;
    for (auto &ch : str)
    {
      if (ch != ' ')
      {
        break;
      }
      index++;
    }
    int sign = +1;
    if (str[index] == '-')
    {
      sign = -1;
      index++;
    }

    while (index < str.size())
    {
      if (str[index] - '0' >= 0 && str[index] - '0' <= 9)
      {
        ans = ans * 10 + (str[index] - '0') * sign;
        if (ans > INT_MAX)
          ans = INT_MAX;
        if (ans < INT_MIN)
          ans = INT_MIN;
        index++;
      }
      else
      {
        break;
      }
    }
    cout << "Str -> Int: " << (int)ans;
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