#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    string str = "Racecar";
    bool ans = check_palindrome(str);
    if (ans)
    {
      cout << "String Is Palindrome";
    }
    else
    {
      cout << "String is not Palindrome";
    }
  }

private:
  bool check_palindrome(string &str)
  {
    for (auto &ch : str)
    {
      ch = tolower(ch);
    }

    int i = 0, j = str.size() - 1;

    while (i < j)
    {
      if (str[i] != str[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}