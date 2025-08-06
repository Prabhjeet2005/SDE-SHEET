#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int> arr = {10, 5, 10, 15, 10, 5};

    unordered_map<int,int>freq_count_map;

    for(int i=0; i<arr.size(); i++){
      freq_count_map[arr[i]]++;
    }

    for(auto &it : freq_count_map){
      cout<<it.first<<" -> "<<it.second<<endl;
    }
  }
};

int main(){
  Solution sol = Solution();
  sol.solution();
  cout<<endl;
}