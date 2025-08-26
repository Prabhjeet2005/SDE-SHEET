#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 5, 8, 15, 1}; // 3
    int target = 9;
    int start = 0, end = arr.size() - 1, ansIndex = -1;

    while (start <= end)
    {
      long long mid = start + (end - start) / 2;
      if (arr[mid] >= target)
      {
        ansIndex = (int)mid;\
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    cout << "Lower Bound: " << ansIndex;
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