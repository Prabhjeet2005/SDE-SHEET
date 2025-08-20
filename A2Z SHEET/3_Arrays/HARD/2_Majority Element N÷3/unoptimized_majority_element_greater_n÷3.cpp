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

    for (int i = 0; i < arr.size(); i++)
    {
      if (find(ans.begin(), ans.end(), arr[i]) != ans.end())
      {
        continue;
      }
      int frequency = 0;
      for (int j = 0; j < arr.size(); j++)
      {
        if (arr[i] == arr[j])
        {
          frequency++;
        }
      }
      if (frequency > floor(arr.size() / 3))
      {
        ans.push_back(arr[i]);
      }
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
  cout << endl;
  sol.solution();
  cout << endl;
  cout << endl;
  return 0;
}