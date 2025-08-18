#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {100, 200, 1, 3, 2, 4};

    int longestSequence = 1;
    int currentSequence = 1;

    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++)
    {
      set.insert(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
      if (set.find(arr[i] - 1) == set.end())
      {
        int cnt = 1;
        currentSequence = 1;
        while (set.find(arr[i] + cnt) != set.end())
        {
          cnt++;
          currentSequence++;
        }
        longestSequence = max(longestSequence, currentSequence);
      }
    }

    cout << "Longest Consecutive Sequence: " << longestSequence << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}