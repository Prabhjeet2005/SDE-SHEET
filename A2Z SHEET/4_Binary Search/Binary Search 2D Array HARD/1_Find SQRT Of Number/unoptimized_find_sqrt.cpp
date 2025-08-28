#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    int n = 37;
    int sqrtValue = 1;
    for(int i=1; i<=n/2; i++){
      if(i*i>n){
        break;
      }
      sqrtValue = i;
    }
    cout<<"Sqrt: "<<sqrtValue;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}