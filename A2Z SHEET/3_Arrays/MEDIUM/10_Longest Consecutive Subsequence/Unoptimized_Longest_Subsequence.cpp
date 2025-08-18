#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  bool linearSearch(vector<int> &arr, int i, int j)
  {
    for (int k = 0; k < arr.size(); k++)
    {
      if (arr[i] + j + 1 == arr[k])
      {
        return true;
      }
    }
    return false;
  }

public:
  void solution()
  {
    vector<int> arr = {100, 200, 1, 3, 2, 4};
    int longestSequence = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      int currentSequence = 1;
      for (int j = 0; j < arr.size(); j++)
      {
        if (linearSearch(arr, i, j))
        {
          currentSequence++;
          longestSequence = max(longestSequence, currentSequence);
        }
        else
        {
          break;
        }
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