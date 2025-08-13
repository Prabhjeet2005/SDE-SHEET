#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9};
    unordered_set<int> set;
    int missingNumber = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      set.insert(arr[i]);
    }

    for (int i = 1; i <= set.size() + 1; i++)
    {
      if (set.find(i) == set.end())
      {
        missingNumber = i;
        break;
      }
    }
    cout << "Missing Number: " << missingNumber << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}