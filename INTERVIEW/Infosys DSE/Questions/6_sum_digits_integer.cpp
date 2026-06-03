#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution(){
      int number = 264589;
      int ans = find_sum_digits(number);
      cout<<"Sum Of Digits is: "<<ans<<"\n";
  }
  private:
  int find_sum_digits(int number){
    int ans = 0;

    while(number!=0){
      int remainder = number%10;
      number /= 10;
      ans += remainder;
    }
    return ans;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}