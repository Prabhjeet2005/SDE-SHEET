#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7, 8, 9};
    int n = arr.size();

    set<int> set;

    for (int i = 0; i < n; i++)
    {
      set.insert(arr[i]);
    }

    auto iterator = 0;
    int size_set = set.size();

    int i = 0;
    for (auto &it : set)
    {
      arr[i++] = it;
    }

    for (int i = 0; i < size_set; i++)
    {
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}