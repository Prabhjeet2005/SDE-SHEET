#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    string str = "A man, a plan, a canal: Panama";
    int start = 0, end = str.size() - 1;
    bool flag = false;
    while (start < end)
    {
      if (!isalnum(str[start]))
      {
        start++;
      }
      else if (!isalnum(str[end]))
      {
        end--;
      }
      else if (tolower(str[start]) != tolower(str[end]))
      {
        cout << "Not Palindrome" << endl;
        flag = true;
        break;
      }
      else
      {
        start++;
        end--;
      }
    }

    if (!flag)
    {
      cout << "It is Palindrome" << endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}