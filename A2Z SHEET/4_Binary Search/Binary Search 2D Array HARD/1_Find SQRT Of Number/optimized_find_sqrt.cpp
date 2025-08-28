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
    int start = 1,end = n;
    while(start <= end){
      int mid = start + (end-start)/2;
      if(mid * mid <= n){
        sqrtValue = mid;
        start = mid+1;
      }else{
        end = mid-1;
      }
    }
    cout << "Sqrt: " << sqrtValue;
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