#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {11, 33, 33, 11, 33, 11, 11};
    vector<int> ans;
    int count1 = 0, count2 = 0, element1 = INT_MIN, element2 = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
      if (count1 == 0 && element2 != arr[i])
      {
        count1++;
        element1 = arr[i];
      }
      else if (count2 == 0 && element1 != arr[i])
      {
        count2++;
        element2 = arr[i];
      }
      else if (element1 == arr[i])
      {
        count1++;
      }
      else if (element2 == arr[i])
      {
        count2++;
      }
      else
      {
        count1--;
        count2--;
      }
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == element1)
        count1++;
      if (arr[i] == element2)
        count2++;
    }

    if (count1 > floor(arr.size() / 3))
      ans.push_back(element1);
    if (count2 > floor(arr.size() / 3))
      ans.push_back(element2);

    for (auto &it : ans)
      cout << it << ", ";
  }
};

int main()
{
  Solution sol = Solution();
  cout << endl;
  sol.solution();
  cout << endl;
  cout << endl;
  return 0;
}