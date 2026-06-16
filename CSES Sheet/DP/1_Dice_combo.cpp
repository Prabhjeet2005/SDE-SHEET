#include<iostream>
#include<vector>
using namespace std;

int MOD = 1e9+7;
vector<int>dp;

long long count_ways(int n){
  if(n<0){
    return 0;
  }
  if(n==0){
    return 1;
  }
  if(dp[n]!=-1)return dp[n];
  long long ans = 0;
  for(int i=1; i<=6; i++){
    ans += count_ways(n-i)%MOD;
  }
  return dp[n] = ans%MOD;
}

long long solution(int n){
  long long ans = -1;
  dp.resize(n+1,-1);
  ans = count_ways(n);
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout << solution(n);
}