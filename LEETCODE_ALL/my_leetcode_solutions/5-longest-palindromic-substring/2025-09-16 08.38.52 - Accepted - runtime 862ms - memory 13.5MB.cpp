class Solution {
    bool isPalindrome(string &s, int startIdx, int endIdx)
  {
    while (startIdx < endIdx)
    {
      if (s[startIdx] != s[endIdx])
      {
        return false;
      }
      startIdx++;
      endIdx--;
    }
    return true;
  }
public:
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
    int maxSize = INT_MIN;
    string ans = "";
    isPalindrome(s, 0, s.size() - 1);
    for (int i = 0; i < s.size() - 1; i++)
    {
      for (int j = i ; j < s.size(); j++)
      {
        if (isPalindrome(s, i, j) == true)
        {
          if (maxSize < j - i + 1)
          {
            maxSize = j-i+1;
            ans = s.substr(i, j - i + 1);
          }
        }
      }
    }
    return ans;
    }
};