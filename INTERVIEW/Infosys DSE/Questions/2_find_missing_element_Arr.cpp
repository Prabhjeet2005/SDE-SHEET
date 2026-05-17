#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int>arr={0,1,3};

    int xor_n = 0,xor_arr=0;

    for(int i=0; i<arr.size(); i++){
      xor_arr ^= arr[i];
    }

    for(int i=0; i<=arr.size(); i++){
      xor_n ^= i;
    }
    int ans = xor_n ^ xor_arr;
    cout<<"Missing: "<< ans << endl;

  }
};

int main(){
  Solution sol =  Solution();
  sol.solution();
}