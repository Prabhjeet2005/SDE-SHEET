#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  int solve(int end,int &sumFirstN){
    if(end <=0){
      return 0;
    }
    solve(end-1,sumFirstN);
    return sumFirstN += end;
  }
public:
  void solution(int n) {
    int sumFirstN = 0;
    int ans = solve(n,sumFirstN);
    cout<<"Sum Of First N: "<<ans<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(7);
  cout << endl;
}