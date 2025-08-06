#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    unordered_map<int, int> freq_count;
    for (int i = 0; i < arr.size(); i++)
    {
      freq_count[arr[i]]++;
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;
    int mini_element = 0;
    int maxi_element = 0;

    for (auto &it : freq_count)
    {
      mini = min(mini, it.second);
      if (mini == it.second)
      {
        mini_element = it.first;
      }
      maxi = max(maxi, it.second);
      if (maxi == it.second)
      {
        maxi_element = it.first;
      }
    }
    cout << "Min Element : " << mini_element << " -> " << mini << endl;
    cout << "Max Element : " << maxi_element << " -> " << maxi << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}