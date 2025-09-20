#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution(vector<int> &arr) {}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  int testcases = 0;
  cin >> testcases;
  while (testcases > 0)
  {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    sol.solution(arr);
    cout << "\n";
    testcases--;
  }
}