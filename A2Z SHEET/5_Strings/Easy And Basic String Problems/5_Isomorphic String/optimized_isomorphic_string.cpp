#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    string str1 = "abbab";
    string str2 = "baaba";
    vector<int> lastPositionStr1(256, -1), lastPositionStr2(256, -1);

    for (int i = 0; i < str1.size(); i++)
    {
      if (lastPositionStr1[str1[i]] != lastPositionStr2[str2[i]])
      {
        cout << "Not ISOMORPHIC";
        return;
      }
      lastPositionStr1[str1[i]] = i;
      lastPositionStr2[str2[i]] = i;
    }
    cout << "ISOMORPHIC";
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