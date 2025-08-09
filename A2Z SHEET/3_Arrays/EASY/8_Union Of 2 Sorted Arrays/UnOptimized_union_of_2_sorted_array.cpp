#include <iostream>
#include <vector>
#include<set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int>ans;
    set<int> set;

    for(int i=0; i<arr1.size() ;i++){
      set.insert(arr1[i]);
    }
    for(int i=0; i<arr2.size() ;i++){
      set.insert(arr2[i]);
    }

    for(auto &it:set){
      ans.push_back(it);
    }

    for(auto &it : ans){
      cout<<it<<", ";
    }
    
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}