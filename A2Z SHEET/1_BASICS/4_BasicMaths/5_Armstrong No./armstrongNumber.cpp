#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int number)
  {
    int numCpy = number;
    int remainder = 0;
    int Armstrong = 0;
    while (numCpy != 0)
    {
      remainder = numCpy % 10;
      numCpy /= 10;
      Armstrong += (remainder * remainder * remainder);
    }

    if (Armstrong == number)
    {
      cout << "It Is ArmStrong Number" << endl;
    }
    else
    {
      cout << "Not an ArmStrong Number" << endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(153);
}