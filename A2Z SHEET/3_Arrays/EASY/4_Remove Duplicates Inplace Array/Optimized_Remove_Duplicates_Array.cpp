#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7, 8, 9};
    int n = arr.size();

    int current = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[current] == arr[i])
      {
        continue;
      }
      current++;
      arr[current] = arr[i];
    }

    for (int i = 0; i <= current; i++)
    {
      cout << arr[i] << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}