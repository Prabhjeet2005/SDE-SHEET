#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int> arr = {2, 4, 6, 8, 10};
    vector<vector<int>>queries = {{1,3},{0,2}};
    int n = arr.size();
    vector<int>prefix_sum(n+1,0);
    int sum = 0;
    for(int i=0; i<n; i++){
      sum += arr[i];
      prefix_sum[i] = sum;
    }

    vector<int>result(queries.size(),0);
    // QUERYING
    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0], r = queries[i][1];
      if(l==0){
        result[i] = prefix_sum[r];
      }else{
        result[i] = prefix_sum[r] - prefix_sum[l-1];
      }
    }

    for(auto &element:result){
      cout<<element<<"\n";
    }
  }
};

int main(){
  Solution sol = Solution();
  cout<<"\n";
  sol.solution();
  cout<<"\n";

}
