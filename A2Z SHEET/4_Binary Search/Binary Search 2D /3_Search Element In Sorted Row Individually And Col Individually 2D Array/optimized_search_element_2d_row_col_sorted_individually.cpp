#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    int target = 14;

    int startRow = 0, startCol = arr[0].size() - 1;
    while (startRow < arr.size() && startCol >= 0)
    {
      if (target == arr[startRow][startCol])
      {
        cout << "Found";
        return;
      }
      else if (arr[startRow][startCol] < target)
      {
        startRow++;
      }
      else
      {
        startCol--;
      }
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}