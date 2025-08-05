#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int &num) {
    int count=0;
    while(num!=0){
      num = num / 10;
      count++;
    }
    cout<<"Count:"<<count<<endl;
  }
};

int main()
{
  int num = 12345;
  Solution sol = Solution();
  sol.solution(num);
}