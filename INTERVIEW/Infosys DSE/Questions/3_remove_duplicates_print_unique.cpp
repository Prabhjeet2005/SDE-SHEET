#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int>arr = {1,1,2,3,4,4,3,5};

    vector<int>ans = remove_duplicates(arr);

    for(auto&element:ans){
      cout<<element<<", ";
    }
  }
  private:
  vector<int>remove_duplicates(vector<int>&arr){
    vector<int>ans;
    unordered_map<int,int>freq;

    for(auto &element:arr){
        freq[element]++;
    }

    for(auto &element_freq:freq){
      if(element_freq.second == 1){
        ans.push_back(element_freq.first);
      }
    }

    return ans;
  }
};

int main(){
  Solution sol = Solution();
  sol.solution();
}