#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 1;
    int maxi = *max_element(arr.begin(), arr.end());

    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      int missingNumber = arr[mid] - (mid + 1);
      if (missingNumber < k)
        start = mid + 1;
      else
        end = mid - 1;
    }
    cout << "Missing Number: " << k + end + 1;
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