#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution
{

public:
  void solution(int x)
  {
    int remainder = 0, numCpy = x, finalAns = 0;
    while (numCpy != 0)
    {
      remainder = numCpy % 10;
      numCpy /= 10;
      if (finalAns > INT_MAX / 10 || finalAns < INT_MIN / 10)
      {
        return;
      }

      finalAns = (finalAns * 10) + remainder;
    }
    cout << finalAns << endl;
    ;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(-123);
}