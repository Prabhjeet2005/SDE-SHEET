#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    int n = arr.size();
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (visited[arr[i]])
      {
        continue;
      }
      visited[arr[i]] = true;
      int count = 0;
      for (int j = 0; j < n; j++)
      {
        if (arr[j] == arr[i])
        {
          count++;
        }
      }
      cout << "Count Of " << arr[i] << " : " << count << endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}