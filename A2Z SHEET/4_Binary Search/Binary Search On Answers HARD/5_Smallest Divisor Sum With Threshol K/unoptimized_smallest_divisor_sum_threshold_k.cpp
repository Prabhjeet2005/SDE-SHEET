#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {8, 4, 2, 3};
    int threshold = 10, ans = -1;
    int maxi = *max_element(arr.begin(), arr.end());

    for (int divisor = 1; divisor <= maxi; divisor++)
    {
      int currentSum = 0;
      for (int i = 0; i < arr.size(); i++)
      {
        currentSum += ceil((double)arr[i] / divisor);
        if (currentSum > threshold)
          break;
      }
      if (currentSum <= threshold)
      {
        ans = divisor;
        break;
      }
    }
    cout << "Minimum divisor: " << ans;
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