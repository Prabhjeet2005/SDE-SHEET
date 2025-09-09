#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int n = arr.size();
    vector<int> gasStation(n - 1, 0);

    // Insert Gas Station at Max Section Length
    for (int i = 1; i <= k; i++)
    {
      int maxSection = INT_MIN, maxSectionIndex = -1;
      for (int j = 0; j < n - 1; j++)
      {
        long double currentSectionLength = (long double)(arr[j + 1] - arr[j]) / (long double)(gasStation[j] + 1);
        if (currentSectionLength > maxSection)
        {
          maxSectionIndex = j;
          maxSection = currentSectionLength;
        }
      }
      gasStation[maxSectionIndex]++;
    }
    // Find Max Section Length
    long double ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
      long double sectionLength = (long double)(arr[i + 1] - arr[i]) / (long double)(gasStation[i] + 1);

      ans = max(ans, sectionLength);
    }

    cout << "Max Gas Station Distance: " << ans;
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