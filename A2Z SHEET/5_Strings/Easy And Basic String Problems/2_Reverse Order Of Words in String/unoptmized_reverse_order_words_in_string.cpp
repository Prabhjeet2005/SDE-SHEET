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
    string str = "This is decent";
    stack<string> stack;
    string temp = "";
    for (auto &ch : str)
    {
      if (ch == ' ')
      {
        stack.push(temp);
        temp = "";
        continue;
      }
      temp += ch;
    }
    if (temp != "")
      stack.push(temp);
    string ans = "";
    while (stack.size() > 1)
    {
      auto top = stack.top();
      stack.pop();
      ans += top + " ";
    }
    auto top = stack.top();
    ans += top;
    cout << "Reversed Order String: " << ans;
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