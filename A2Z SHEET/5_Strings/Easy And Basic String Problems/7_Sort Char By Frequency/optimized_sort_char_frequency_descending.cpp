#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
  static bool customOperator(pair<char, int> &s1, pair<char, int> &s2)
  {
    if (s1.second > s2.second)
      return true;
    if (s1.second < s2.second)
      return false;
    return s1.first < s2.first; // Return smaller Occuring Character
  }

public:
  void solution()
  {
    string str = "cccfghwwwwwwAabb";
    vector<pair<char, int>> frequency(256, {NULL, 0});
    for (auto &ch : str)
    {
      frequency[(int)ch].first = ch;
      frequency[(int)ch].second += 1;
    }
    sort(frequency.begin(), frequency.end(), customOperator);
    string ans = "";
    for (auto &element : frequency)
    {
      if (element.second != 0)
      {
        for (int i = 0; i < element.second; i++)
          ans += element.first;
      }
    }
    cout << ans;
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