#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
  public:
  void solution(int n){
    if(n<=0){
      return;
    }
    cout<<"Prabhjeet"<<", ";
    solution(n-1);
  }
};

int main(){
  Solution sol = Solution();
  sol.solution(5);
  cout<<endl;
}