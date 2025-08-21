#include <iostream>
#include <vector>
#include <set>
#include<unordered_set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    set<vector<int>> ansSet;

    for(int i=0; i<arr.size(); i++){
      unordered_set<int>visitedElements;
      for(int j=i+1; j<arr.size(); j++){
        int thirdElement = target - (arr[i]+arr[j]); // Formula For Lookup
        if(visitedElements.find(thirdElement) != visitedElements.end()){
          vector<int>tempArr = {arr[i],arr[j],thirdElement};
          sort(tempArr.begin(),tempArr.end());
          ansSet.insert(tempArr);
        }
        visitedElements.insert(arr[j]);
      }
    }

    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    for (auto &it : ans)
    {
      cout << "{";
      for (auto &element : it)
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