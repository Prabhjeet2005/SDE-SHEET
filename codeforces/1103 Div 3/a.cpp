#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&arr){
  int max_height=-1e9;
  int min_height = 1e9;
  for(auto &element:arr){
    max_height = max(max_height,element);
    min_height = min(min_height,element);
  }
  return max_height+1 - min_height;
}

int main(){
  cout<<"\n\n";
  int t;
  cin>>t;
  for(int i=0; i<t; i++){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
      cin>>arr[i];
    }
    cout<<solve(n,arr)<<"\n";
  }
}