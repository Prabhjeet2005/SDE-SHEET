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
    unordered_map<int,int>map;

    for (int i = 0; i < arr.size(); i++)
    {
      map[arr[i]]++;
    }

    for (auto &it : map)
    {
      if(it.second > floor(arr.size()/3)){
        ans.push_back(it.first);
      }
    }

    for(auto& it: ans){
      cout<<it<<", ";
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