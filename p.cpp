#include<iostream>
using namespace std;

int MOD = 1e9+7;


int main(){
  vector<int>arr = {1,2,3,4,5};

  int n = arr.size();
  vector<int>prefix_sum(n+1,0);
  int sum = 0;

  for(int i=1; i<=n; i++){
    sum += arr[i-1];
    prefix_sum[i] = sum;
  }

  // Query: {0,3} -> Range L:0, R:3 -> OUTPUT: 10

  cout<<"Range Query: "<<prefix_sum[3+1] - prefix_sum[0];

}