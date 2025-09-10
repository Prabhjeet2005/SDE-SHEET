#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 4}, {3, 2}};
    bool found = false;
    for (int row = 0; row < arr.size(); row++)
    {
      for (int col = 0; col < arr[0].size(); col++)
      {
      bool currentPeak = true; // For Current  Element
        int top = row - 1, right = col + 1, left = col - 1, bottom = row + 1;
        if (top >= 0 && arr[top][col] >= arr[row][col])
          currentPeak = false;
        if (left >= 0 && arr[row][left] >= arr[row][col])
          currentPeak = false;
        if (right < arr[0].size() && arr[row][right] >= arr[row][col])
          currentPeak = false;
        if (bottom < arr.size() && arr[bottom][col] >= arr[row][col])
          currentPeak = false;

        if (currentPeak)
        {
          cout << "Peak found: " << row << "," << col;
          return;
        }
      }
    }
    cout << "Peak Not Found";
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