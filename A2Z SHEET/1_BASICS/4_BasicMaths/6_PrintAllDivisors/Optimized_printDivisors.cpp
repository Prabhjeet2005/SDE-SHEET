#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  void solution(int n)
  {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++)
    {
      if (n % i == 0)
      {
        // For Eg: 3 x  12 = 36
        divisors.push_back(i); // Eg. Added 3 Here

        if (n / i != i)
        {
          divisors.push_back(n / i); // Add Counter Part 12 Here
        }
      }
    }
    sort(divisors.begin(),divisors.end());
    for (auto &it : divisors)
    {
      cout << it << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(36);
}