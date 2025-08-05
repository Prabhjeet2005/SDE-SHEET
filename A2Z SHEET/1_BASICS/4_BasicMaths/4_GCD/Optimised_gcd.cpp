#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int num1, int num2)
  {
    int ans = 1;
    while (num1 != 0 && num2 != 0)
    {
      if (num1 > num2)
      {
        num1 = num1 - num2;
      }
      else
      {
        num2 = num2 - num1;
      }
    }
    cout << "GCD: " << max(num1, num2) << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(12, 24);
}