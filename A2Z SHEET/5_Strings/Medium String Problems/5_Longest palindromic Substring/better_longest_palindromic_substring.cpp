#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  pair<int, int> getMaxPalindromeLength(string &str, int left, int right)
  {
    while(left >= 0 && right < str.size() && str[left] == str[right]){
      left--;right++;
    }
    return {left + 1,(right - 1)-(left+1)+1};
  }

public:
  void solution()
  {
    vector<int> arr = {};
    string str = "babad";
    int maxLength = INT_MIN;
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
      // pair<start,length>
      pair<int, int> len1 = getMaxPalindromeLength(str, i, i);     // ODD LENGTH
      pair<int, int> len2 = getMaxPalindromeLength(str, i, i + 1); // EVEN LENGTH

      int currentMaxLength = max({len1.second, len2.second});

      if (currentMaxLength > maxLength)
      {
        maxLength = currentMaxLength;
        if (len1.second == currentMaxLength)
        {
          ans = str.substr(len1.first, len1.second);
        }
        else
        {
          ans = str.substr(len2.first, len2.second);
        }
      }
    }
    cout << "Longest palindromic Substring: " << ans;
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