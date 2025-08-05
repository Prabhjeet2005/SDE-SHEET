#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  bool solution(int x)
  {
    if (x < 0)
    {
      return false;
    }
    long reverse = 0, remainder = 0, number = x;
    while (number != 0)
    {
      remainder = number % 10;
      number /= 10;
      reverse = reverse * 10 + remainder;
    }
    if (reverse == x)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution sol = Solution();
  cout << "Is Palindrome: " << sol.solution(12321) << endl;
}