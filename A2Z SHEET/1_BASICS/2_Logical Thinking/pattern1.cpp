#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int n) {
    for(int i = 0; i<n; i++){
      for(int i=0; i<n; i++){
        cout<<"*";
      }
      cout<<endl;
    }
  }
};

int main()
{
  int n;
  cout<<"Enter n: ";
  cin>>n;
  Solution sol = Solution();
  sol.solution(n);
}