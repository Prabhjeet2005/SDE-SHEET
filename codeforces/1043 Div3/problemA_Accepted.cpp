#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Solution
{

public:
  string solution(int &aLen, int &bcLen, string &a, string &b, string &c)
  {
    // D -> end, V -> begin

    for (int i = 0; i < bcLen; i++)
    {
      if (c[i] == 'D')
      {
        a.push_back(b[i]);
      }
      else
      {
        a.insert(a.begin(), b[i]);
      }
    }
    return a;
  }
};

int main()
{
  Solution sol = Solution();
  vector<int> S;
  vector<int> T;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int j = 0; j < t; j++)
  {
    int aLen, bcLen;
    string a, b, c;
    cin >> aLen >> a >> bcLen >> b >> c;

    string ans = sol.solution(aLen, bcLen, a, b, c);

    cout << ans <<"\n";
  }

}