#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int n)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        cout << j+1;
      }
      cout << endl;
    }
  }
};

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  Solution sol = Solution();
  sol.solution(n);
}