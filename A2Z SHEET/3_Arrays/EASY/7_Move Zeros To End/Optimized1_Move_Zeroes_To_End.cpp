#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 0, 23, 4, 5, 0, 8, 0, 9, 0};
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        count++;
      }
    }
    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
    for (int i = 0; i < count; i++)
    {
      arr.push_back(0);
    }

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}