#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    string str = "MCMXCIV";
    int romanToInt = 0;
    unordered_map<char, int> map = {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
    for (int i = 0; i < str.size(); i++)
    {
      if (i + 1 < str.size() && map[str[i]] < map[str[i + 1]])
      {
        // Subtract
        romanToInt -= map[str[i]];
      }
      else
      {
        // Add
        romanToInt += map[str[i]];
      }
    }
    cout << "Roman -> INT: " << romanToInt;
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