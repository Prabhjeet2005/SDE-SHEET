#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 4}, {3, 2}};
    int start = 0, end = arr[0].size();
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      auto maxi = INT_MIN, maxi_index = -1;
      for (int i = 0; i < arr.size(); i++)
      {
        if (arr[i][mid] > maxi)
        {
          maxi = arr[i][mid];
          maxi_index = i;
        }
      }
      int leftElement = mid - 1 < 0 ? -1 : arr[maxi_index][mid - 1];
      int rightElement = mid + 1 >= arr[0].size() ? -1 : arr[maxi_index][mid + 1];
      bool leftGreater = leftElement < arr[maxi_index][mid];
      bool rightGreater = arr[maxi_index][mid] > rightElement;
      if (leftGreater && rightGreater)
      {
        cout << "Found Peak At: " << maxi_index << ", " << mid;
        return;
      }
      else if (leftElement < arr[maxi_index][mid] && arr[maxi_index][mid] < rightElement)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
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