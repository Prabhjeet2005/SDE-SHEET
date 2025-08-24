#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    int n = arr.size();
    int missingNumber = -1, repeatingNumber = -1;
    unordered_map<int, int> map;

    for (int i = 1; i <= n; i++)
    {
      map[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
      map[arr[i]]++;
    }

    for (auto &it : map)
    {
      if (it.second == 0)
      {
        missingNumber = it.first;
      }
      if (it.second == 2)
      {
        repeatingNumber = it.first;
      }
    }

    cout << "Missing Number: " << missingNumber << "\nRepeating Number: " << repeatingNumber;
  }
};
int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}