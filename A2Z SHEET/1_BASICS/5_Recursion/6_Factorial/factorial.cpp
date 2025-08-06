#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void solve(int n,int &factorial){
    if(n<=1){
      return;
    }
    factorial *= n;
    solve(n-1,factorial);
  }
public:
  void solution(int n) {
    int factorial = 1;
    solve(n,factorial);
    cout<<"Factorial Of "<<n<<" is: "<<factorial;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(5);
  cout << endl;
}