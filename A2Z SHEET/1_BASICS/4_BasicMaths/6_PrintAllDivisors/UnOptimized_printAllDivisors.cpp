#include <iostream>
#include <vector>
#include <unordered_set>
#include<math.h>

using namespace std;

class Solution
{

public:
  void solution(int num)
  {
    unordered_set<int> set;
    for (int i = num; i > 1; i--)
    {
      if (num % i == 0)
      {
        set.insert(i);
      }
    }
    set.insert(1);

    for (auto &it : set)
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