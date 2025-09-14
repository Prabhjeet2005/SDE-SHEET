#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{

public:
  void solution()
  {
    string str1 = "anagram";
    string str2 = "naargma";

    sort(str1.begin(), str1.end());
    sort(str2.begin(),str2.end());

    if (str1 == str2)
    {
      cout << "Valid Anagram";
      return;
    }
    cout << "Invalid Anagram";
    return;
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