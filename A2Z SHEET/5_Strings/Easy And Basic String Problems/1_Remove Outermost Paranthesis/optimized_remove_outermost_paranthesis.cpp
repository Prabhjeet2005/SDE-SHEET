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
    int paranthesisCount=0;

    for (char &ch : str)
    {
      if (ch == '(')
      {
        if(paranthesisCount != 0) ans+="(";
        paranthesisCount++;
      }
      else
      {
        if(paranthesisCount > 1) ans+=")";
        paranthesisCount--;
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