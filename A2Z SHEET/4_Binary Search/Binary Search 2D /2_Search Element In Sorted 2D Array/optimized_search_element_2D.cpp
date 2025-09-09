#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 10;
    int rowSize = arr.size(), colSize = arr[0].size();
    int start = 0, end = rowSize * colSize - 1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid / colSize][mid % colSize] == target)
      {
        cout << "Found";
        return;
      }
      else if (arr[mid / colSize][mid % colSize] < target)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
    cout << "Not Found";
    return;
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