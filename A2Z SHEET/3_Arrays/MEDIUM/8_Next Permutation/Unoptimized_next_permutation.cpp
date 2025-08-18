#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  void swap(vector<int> &arr, int first, int second)
  {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }
  void generateAllPermutations(vector<int> &arr, vector<vector<int>> &ans, int index)
  {
    if (index >= arr.size())
    {
      ans.push_back(arr);
      return;
    }

    for (int i = index; i < arr.size(); i++)
    {
      swap(arr, index, i);
      generateAllPermutations(arr, ans, index + 1);
      swap(arr, index, i);
    }
  }

public:
  void solution()
  {
    vector<int> arr = {3, 2, 1};
    vector<int> arrCpy = arr;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    generateAllPermutations(arr, ans, 0);

    sort(ans.begin(), ans.end());

    auto iterator = find(ans.begin(), ans.end(), arrCpy);
    if (iterator != ans.end())
    {
      iterator++;
      if (iterator != ans.end())
      {
        for (auto &it : *iterator)
        {
          cout << it << ", ";
        }
        cout << endl;
      }
      else
      {
        for (auto &it : ans[0])
        {
          cout << it << ", ";
        }
        cout << endl;
      }
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}