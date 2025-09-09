#include <iostream>
#include <vector>
#include <queue>

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
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < arr.size() - 1; i++)
    {
      pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gas = 1; gas <= k; gas++)
    {
      long double maxSectionLength = -1;
      int maxSectionIndex = -1;

      auto top = pq.top();
      pq.pop();
      int index = top.second;
      gasStation[index]++;
      pq.push({(long double)(arr[index + 1] - arr[index]) / (long double)(gasStation[index] + 1), index});
    }

    cout << "Max Distance B/w Gas Station: " << pq.top().first;
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