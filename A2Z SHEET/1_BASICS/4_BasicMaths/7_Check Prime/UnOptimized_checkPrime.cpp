#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution(int n)
  {
    bool flag = false;
    for (int i = 2; i < n; i++)
    {
      if (n % i == 0)
      {
        flag = true;
        break;
      }
    }
    if (!flag)
    {
      cout << "Is Prime\n";
    }
    else
    {
      cout << "Not A Prime\n";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(97);
}