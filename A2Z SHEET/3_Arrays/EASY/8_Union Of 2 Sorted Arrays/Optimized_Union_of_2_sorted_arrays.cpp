#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    // Element Already exists move ptr++
    // if ptr1 == ptr2 , add either & increase the ptr1++ ptr2++
    // ptr1  < ptr2, then add ptr1 & ptr1++
    // ptr1  > ptr2, then add ptr2 & ptr2++
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> ans;

    int ptr1 = 0;
    int ptr2 = 0;

    int n = arr1.size();
    int m = arr2.size();

    while (ptr1 < n && ptr2 < m)
    {
      if (arr1[ptr1] <= arr2[ptr2])
      {
        if (ans.size() == 0 || ans.back() != arr1[ptr1])
        {
          ans.push_back(arr1[ptr1]);
        }
        ptr1++;
      }
      else
      {
        if (ans.size() == 0 || ans.back() != arr2[ptr2])
        {
          ans.push_back(arr2[ptr2]);
        }
        ptr2++;
      }
    }

    while (ptr1 < n)
    {
      if (ans.back() != arr1[ptr1])
      {
        ans.push_back(arr1[ptr1]);
      }
      ptr1++;
    }
    while (ptr2 < m)
    {
      if (ans.back() != arr2[ptr2])
      {
        ans.push_back(arr2[ptr2]);
      }
      ptr2++;
    }

    for (auto &it : ans)
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