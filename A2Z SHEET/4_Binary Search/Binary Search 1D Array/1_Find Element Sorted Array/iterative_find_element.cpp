#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (mid == target)
      {
        cout << "Element Found";
        return;
      }
      else if (mid > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    cout << "Element Not Found";
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