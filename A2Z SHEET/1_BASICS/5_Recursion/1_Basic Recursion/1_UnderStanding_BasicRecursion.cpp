#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution(int n) {
    if(n<0){
      return;
    }
    cout<<n<<" ";
    solution(n-1);
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(3);
  cout<<endl;
}