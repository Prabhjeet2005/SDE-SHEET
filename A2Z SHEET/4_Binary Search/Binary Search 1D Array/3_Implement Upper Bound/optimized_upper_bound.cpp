#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 5, 8, 9, 15, 19}; // 4
    int target = 9;
    int start = 0, end = arr.size() - 1, ansIndex = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] <= target)
      {
        ansIndex = mid;
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    cout << "Upper Bound: " << ansIndex;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution solObj = Solution();
  cout << "\n";
  solObj.solution();
  cout << "\n";
}