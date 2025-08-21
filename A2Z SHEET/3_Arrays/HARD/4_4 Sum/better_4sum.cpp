#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    set<vector<int>> ansSet;
    int size = arr.size();

    for (int i = 0; i < size - 3; i++)
    {
      for (int j = i + 1; j < size - 2; j++)
      {
        unordered_set<int> visitedElements;
        for (int k = j + 1; k < size; k++)
        {
          int element4 = target - (arr[i] + arr[j] + arr[k]);
          if (visitedElements.find(element4) != visitedElements.end())
          {
            vector<int> tempArr = {arr[i], arr[j], arr[k], element4};
            sort(tempArr.begin(), tempArr.end());
            ansSet.insert(tempArr);
          }
          visitedElements.insert(arr[k]);
        }
      }
    }

    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    for (auto &array : ans)
    {
      cout << "{";
      for (auto &element : array)
      {
        cout << element << ", ";
      }
      cout << "}, ";
    }
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