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
    vector<vector<int>> ans;
    int size = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++)
    {
      if (i != 0 && arr[i - 1] == arr[i])
      {
        continue;
      }

      for (int j = i + 1; j < size; j++)
      {
        if (j != i + 1 && arr[j - 1] == arr[j])
        {
          continue;
        }
        int start = j + 1, end = size - 1;
        while (start < end)
        {
          int sumQuad = arr[i] + arr[j] + arr[start] + arr[end];
          if (sumQuad == target)
          {
            ans.push_back({arr[i], arr[j], arr[start], arr[end]});
            start++;
            end--;
            while (start < end && arr[start - 1] == arr[start])
              start++;
            while (start < end && arr[end] == arr[end + 1])
              end--;
          }
          else if (sumQuad < target)
          {
            start++;
          }
          else if (sumQuad > target)
          {
            end--;
          }
        }
      }
    }

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