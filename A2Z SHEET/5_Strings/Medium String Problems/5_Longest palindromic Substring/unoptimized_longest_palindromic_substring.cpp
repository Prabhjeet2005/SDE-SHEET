#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  bool isPalindrome(string &str, int startIdx, int endIdx)
  {
    while (startIdx < endIdx)
    {
      if (str[startIdx] != str[endIdx])
      {
        return false;
      }
      startIdx++;
      endIdx--;
    }
    return true;
  }

public:
  void solution()
  {
    string str = "babad";
    int maxSize = INT_MIN;
    string ans = "";
    if(isPalindrome(str, 0, str.size() - 1)){
      cout << str;return;
    };
    for (int i = 0; i < str.size() - 1; i++)
    {
      for (int j = i; j < str.size(); j++)
      {
        if (isPalindrome(str, i, j) == true)
        {
          if (maxSize < j - i + 1)
          {
            maxSize = j-i+1;
            ans = str.substr(i, j - i + 1);
          }
        }
      }
    }
    cout << "Longest Palindrome Substring: " << ans;
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