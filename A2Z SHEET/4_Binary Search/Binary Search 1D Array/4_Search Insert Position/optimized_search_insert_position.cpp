#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 4, 7}; // 3
    int target = 6;
    int start = 0, end = arr.size() - 1, ansIndex = arr.size();

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] >= target)
      {
        ansIndex = mid;
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    cout << "Insert Index: " << ansIndex;
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