#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    set<vector<int>> ansSet;

    for(int i=0; i<arr.size();i++){
      for(int j = i+1; j<arr.size(); j++){
        for(int k = j+1; k<arr.size(); k++){
          if(arr[i] + arr[j] + arr[k] == target){
            vector<int>temp = {arr[i],arr[j],arr[k]};
            sort(temp.begin(),temp.end());
            ansSet.insert(temp);
          }
        }
      }
    }

    vector<vector<int>>ans(ansSet.begin(),ansSet.end());
    for(auto& it:ans){
      cout<<"{";
      for(auto & element:it){
        cout<<element<<", ";
      }
      cout<<"}, ";
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