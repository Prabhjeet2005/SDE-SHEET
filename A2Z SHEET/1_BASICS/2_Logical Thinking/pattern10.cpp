#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(int n){
    for(int i=0; i<2*n-1; i++){
      if(i<n){
        for(int j=0; j<=i;j++){
          cout<<"*";
        }
      }else{
        for(int j=0; j<2*n-i-1;j++){
          cout<<"*";
        }
      }
      cout<<endl;
    }
  }
};

int main(){
  int n = 0;
  cout<<"Enter N: ";
  cin>>n;
  Solution sol = Solution();
  sol.solution(n);
}