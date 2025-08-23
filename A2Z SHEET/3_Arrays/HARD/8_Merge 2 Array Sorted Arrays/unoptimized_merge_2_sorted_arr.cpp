#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    vector<int> ans;
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < arr1.size() && ptr2 < arr2.size())
    {
      if (arr1[ptr1] < arr2[ptr2])
      {
        ans.push_back(arr1[ptr1++]);
      }
      else
      {
        ans.push_back(arr2[ptr2++]);
      }
    }
    while (ptr1 < arr1.size())
    {
      ans.push_back(arr1[ptr1++]);
    }
    while (ptr2 < arr2.size())
    {
      ans.push_back(arr2[ptr2++]);
    }

    for (auto &element : ans)
    {
      cout << element << ", ";
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