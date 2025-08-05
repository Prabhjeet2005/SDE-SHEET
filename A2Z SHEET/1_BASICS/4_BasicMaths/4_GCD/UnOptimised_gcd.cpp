#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int num1, int num2) {
    int ans = 1;
    int end = min(num1,num2);
    for(int i = 2; i<=end; i++ ){
      if(num1%i ==0 && num2%i==0){
        ans = i;
      }
    }
    cout<<"GCD: "<<ans<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(12,24);
}