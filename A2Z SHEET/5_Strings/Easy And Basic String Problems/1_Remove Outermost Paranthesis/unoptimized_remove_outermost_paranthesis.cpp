#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  void solution()
  {
    string str = "(()())(())(()(()))";
    string ans = "";
    stack<char> stack;

    for (char &ch : str)
    {
      if (ch == '(')
      {
        if(stack.size()>0)ans+="(";
        stack.push('(');
      }
      else
      {
        if (stack.size() > 1)
        {
          ans += ")";
        }
        stack.pop();
      }
    }
    cout << "Removed Outer Parenthesis: " << ans;
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