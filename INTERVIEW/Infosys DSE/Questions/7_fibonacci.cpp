#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(){
    int n = 10;
    print_fibonacci(n);
  }
  private:
  void print_fibonacci(int n){
    int first = 0,second = 1;

    for(int i=0; i<n; i++){
      if(i <= 1)cout << i <<" ";
      else{
        int temp = first;
        first = second;
        second = temp + second;
        cout<<second<<" ";
      }
    }
  }
};

int main(){
  Solution sol = Solution();
  sol.solution();
}