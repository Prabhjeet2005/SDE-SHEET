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

    vector<int> charMap(256, 0);

    for (int i = 0; i < str1.size(); i++)
    {
      charMap[str1[i] - 'a']++;
    }
    for (int i = 0; i < str2.size(); i++)
    {
      charMap[str2[i] - 'a']--;
    }

    for (int i = 0; i < charMap.size(); i++)
    {
      if (charMap[i] != 0)
      {
        cout << "Invalid Anagram";
        return;
      }
    }
    cout << "Valid Anagram";
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